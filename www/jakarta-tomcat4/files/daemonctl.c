/*
 * -*- mode: Fundamental; tab-width: 4; -*-
 * ex:ts=4
 *
 * Daemon control program.
 *
 * $FreeBSD: /tmp/pcvs/ports/www/jakarta-tomcat4/files/Attic/daemonctl.c,v 1.10 2002-10-09 23:10:32 znerd Exp $
 */

#include <assert.h>
#include <fcntl.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>

/* The maximum size of the PID file, in bytes */
#define MAX_FILE_SIZE			32

/* The interval in seconds between the checks to make sure the process
   died after a kill */
#define STOP_TIME_INTERVAL		1

#define ERR_ILLEGAL_ARGUMENT				1
#define ERR_PID_FILE_NOT_FOUND				2
#define ERR_PID_FILE_TOO_LARGE				3
#define ERR_PID_FILE_CONTAINS_ILLEGAL_CHAR	4
#define ERR_KILL_FAILED						5
#define ERR_ALREADY_RUNNING					6
#define ERR_NOT_RUNNING						7
#define ERR_CHDIR_TO_APP_HOME				8
#define ERR_ACCESS_JAR_FILE					17
#define ERR_STDOUT_LOGFILE_OPEN				9
#define ERR_STDERR_LOGFILE_OPEN				10
#define ERR_FORK_FAILED						11
#define ERR_STAT_JAVA_HOME					12
#define ERR_JAVA_HOME_NOT_DIR				13
#define ERR_STAT_JAVA_CMD					14
#define ERR_JAVA_CMD_NOT_FILE				15
#define ERR_JAVA_CMD_NOT_EXECUTABLE			16

#define private static

private void printUsage(void);
private int openPIDFile(void);
private int readPID(int);
private void writePID(int file, int pid);
private void start(void);
private void stop(void);
private void restart(void);


/**
 * Main function. This function is called when this program is executed.
 *
 * @param argc
 *    the number of arguments plus one, so always greater than 0.
 *
 * @param argv
 *    the arguments in an array of character pointers, where the last argument
 *    element is followed by a NULL element.
 */
int main(int argc, char *argv[]) {

	/* Declare variables, like all other good ANSI C programs do :) */
	char *argument;

	/* Parse the arguments */
	if (argc < 2) {
		printUsage();
		return 0;
	}

	/* XXX: Fix for setting up the environment for the java wrapper script */
	setuid(geteuid());
	setgid(getegid());

	argument = argv[1];
	if (strcmp("start", argument) == 0) {
		start();
	} else if (strcmp("stop", argument) == 0) {
		stop();
	} else if (strcmp("restart", argument) == 0) {
		restart();
	} else {
		fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: Illegal argument \"%s\".\n", argument);
		printUsage();
		exit(ERR_ILLEGAL_ARGUMENT);
	}

	return 0;
}


/**
 * Prints usage information to stdout.
 */
void printUsage(void) {
	printf("Usage: %%CONTROL_SCRIPT_NAME%% [ start | stop | restart ]\n");
}


/**
 * Attempts to open the PID file. If that file is successfully opened, then
 * the file handle (an int) will be returned.
 *
 * @return
 *    the file handle.
 */
int openPIDFile(void) {

 	int file;

	/* Attempt to open the PID file */
	file = open("%%PID_FILE%%", O_RDWR);
	if (file < 0) {
		printf(" [ FAILED ]\n");
		fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to open %%PID_FILE%% for reading and writing: ");
		perror(NULL);
		exit(ERR_PID_FILE_NOT_FOUND);
	}

	return file;
}


/**
 * Reads a PID from the specified file. The file is identified by a file
 * handle.
 *
 * @param file
 *    the file handle.
 *
 * @return
 *    the PID, or -1 if the file was empty.
 */
int readPID(int file) {

	char *buffer;
	int hadNewline = 0;
	unsigned int count;
	unsigned int i;
	int pid;

	/* Read the PID file contents */
	buffer = (char *) malloc((MAX_FILE_SIZE + 1) * sizeof(char));
	count = read(file, buffer, MAX_FILE_SIZE + 1);
	if (count > MAX_FILE_SIZE) {
		printf(" [ FAILED ]\n");
		fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: The file %%PID_FILE%% contains more than %d bytes.\n", MAX_FILE_SIZE);
		exit(ERR_PID_FILE_TOO_LARGE);
	}

	/* Convert the bytes to a number */
	pid = 0;
	for (i=0; i<count; i++) {
		char c = buffer[i];
		if (c >= '0' && c <= '9') {
			char digit = c - '0';
			pid *= 10;
			pid += digit;
		} else if (i == (count - 1) && c == '\n') {
			/* XXX: Ignore a newline at the end of the file */
			hadNewline = 1;
		} else {
			printf(" [ FAILED ]\n");
			fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: The file %%PID_FILE%% contains an illegal character (%d) at position %d.\n", c, i);
			exit(ERR_PID_FILE_CONTAINS_ILLEGAL_CHAR);
		}
	}
	printf(" [ DONE ]\n");

	if (count == 0 || (count == 1 && hadNewline == 1)) {
		return -1;
	}

	return pid;
}


/**
 * Writes a process ID to the specified file. The file is identified by a file
 * handle.
 *
 * @param file
 *    the file handle, always greater than 0.
 *
 * @param pid
 *    the PID to store, always greater than 0.
 */
void writePID(int file, int pid) {

	char *buffer;
	int nbytes;

	/* Check preconditions */
	assert(file > 0);
	assert(pid > 0);

	printf(">> Writing PID file...");

	lseek(file, (off_t) 0, SEEK_SET);
	ftruncate(file, (off_t) 0);
	nbytes = asprintf(&buffer, "%d\n", pid);
	write(file, buffer, nbytes);
	printf(" [ DONE ]\n");
}


/**
 * Checks if the specified process is running.
 *
 * @param pid
 *    the process id, greater than 0.
 *
 * @return
 *    0 if the specified process is not running, a different value otherwise.
 */
int existsProcess(int pid) {

	int result;

	/* Check preconditions */
	assert(pid > 0);

	/* See if the process exists */
   	result = kill(pid, 0);

	/* If the result is 0, then the process exists */
	if (result == 0) {
		return 1;
	} else {
		return 0;
	}
}


/**
 * Kills the process identified by the specified ID.
 *
 * @param pid
 *    the process id, greater than 0.
 */
void killProcess(int pid) {

	int result;
	unsigned int waited;
	unsigned int forced;
	unsigned int interval = STOP_TIME_INTERVAL;
	unsigned int timeout  = %%STOP_TIMEOUT%%;

	/* Check preconditions */
	assert(pid > 0);

	printf(">> Terminating process %d...", pid);
	result = kill(pid, SIGTERM);
	if (result < 0) {
		printf(" [ FAILED ]\n");
		fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to kill process %d: ", pid);
		perror(NULL);
		exit(ERR_KILL_FAILED);
	}

	/* Wait until the process is actually killed */
    result = existsProcess(pid);
	for (waited=0; result == 1 && waited < timeout; waited += interval)
	{
		printf(".");
		fflush(NULL);
		sleep(interval);
    	result = existsProcess(pid);
	}

	/* If the process still exists, then have no mercy and kill it */
	forced = 0;
	if (result == 1) {

		/* Force the process to die */
		result = kill(pid, SIGKILL);
		if (result == 0) {
			forced = 1;
			printf(" [ DONE ]\n");
			fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: Process %d did not terminate within %%STOP_TIMEOUT%% sec. Killed.\n", pid);
		} else if (result != ESRCH) {
			printf(" [ FAILED ]\n");
			fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to kill process %d: ", pid);
			perror(NULL);
			exit(ERR_KILL_FAILED);
		}
	}

	if (forced == 0) {
		printf(" [ DONE ]\n");
	}
}


/**
 * Starts the daemon.
 */
void start(void) {

	int file;
	int pid;
	int result;
	int stdoutLogFile;
	int stderrLogFile;
	struct stat sb;

	/* Open and read the PID file */
	printf(">> Reading PID file (%%PID_FILE%%)...");
	file = openPIDFile();
	pid = readPID(file);

	printf(">> Starting %%APP_TITLE%% %%PORTVERSION%%...");
	if (pid != -1) {

		/* Check if the process actually exists */
		result = existsProcess(pid);
		if (result == 1) {
			printf(" [ FAILED ]\n");
			fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: %%APP_TITLE%% %%PORTVERSION%% is already running, PID is %d.\n", pid);
			exit(ERR_ALREADY_RUNNING);
		}
	}

	/* Check if the JDK home directory is actually a directory */
	result = stat("%%JAVA_HOME%%", &sb);
	if (result != 0) {
		printf(" [ FAILED ]\n");
		fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to stat %%JAVA_HOME%%: ");
		perror(NULL);
		exit(ERR_STAT_JAVA_HOME);
	}
	if (!S_ISDIR(sb.st_mode)) {
		printf(" [ FAILED ]\n");
		fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: Java home directory %%JAVA_HOME%% is not a directory.\n");
		exit(ERR_JAVA_HOME_NOT_DIR);
	}

	/* Check if the Java command is actually an executable regular file */
	result = stat("%%JAVA_HOME%%/%%JAVA_CMD%%", &sb);
	if (result != 0) {
		printf(" [ FAILED ]\n");
		fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to stat %%JAVA_HOME%%/%%JAVA_CMD%%: ");
		perror(NULL);
		exit(ERR_STAT_JAVA_CMD);
	}
	if (!S_ISREG(sb.st_mode)) {
		printf(" [ FAILED ]\n");
		fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: Java command %%JAVA_HOME%%/%%JAVA_CMD%% is not a regular file.\n");
		exit(ERR_JAVA_CMD_NOT_FILE);
	}
	result = access("%%JAVA_HOME%%/%%JAVA_CMD%%", X_OK);
	if (result != 0) {
		printf(" [ FAILED ]\n");
		fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: Java command %%JAVA_HOME%%/%%JAVA_CMD%% is not executable: ");
		perror(NULL);
		exit(ERR_JAVA_CMD_NOT_EXECUTABLE);
	}

	/* Change directory */
	result = chdir("%%APP_HOME%%");
	if (result < 0) {
		printf(" [ FAILED ]\n");
		fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to access directory %%APP_HOME%%: ");
		perror(NULL);
		exit(ERR_CHDIR_TO_APP_HOME);
	}

	/* See if the JAR file exists */
	result = access("%%APP_HOME%%/%%JAR_FILE%%", R_OK);
	if (result < 0) {
		printf(" [ FAILED ]\n");
		fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to access JAR file %%APP_HOME%%/%%JAR_FILE%%: ");
		perror(NULL);
		exit(ERR_ACCESS_JAR_FILE);
	}

	/* Open the stdout log file */
	stdoutLogFile = open("%%STDOUT_LOG%%", O_WRONLY);
	if (stdoutLogFile < 0) {
		printf(" [ FAILED ]\n");
		fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to open %%STDOUT_LOG%% for writing: ");
		perror(NULL);
		exit(ERR_STDOUT_LOGFILE_OPEN);
	}
	lseek(stdoutLogFile, (off_t) 0, SEEK_END);

	/* Open the stderr log file */
	stderrLogFile = open("%%STDERR_LOG%%", O_WRONLY);
	if (stderrLogFile < 0) {
		printf(" [ FAILED ]\n");
		fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to open %%STDERR_LOG%% for writing: ");
		perror(NULL);
		exit(ERR_STDERR_LOGFILE_OPEN);
	}
	lseek(stderrLogFile, (off_t) 0, SEEK_END);

	/* Split this process in two */
	pid = fork();
	if (pid == -1) {
		printf(" [ FAILED ]\n");
		fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to fork: ");
		perror(NULL);
		exit(ERR_FORK_FAILED);
	}

	if (pid == 0) {

		/* Redirect stdout to log file */
		dup2(stdoutLogFile, STDOUT_FILENO);

		/* Redirect stderr to log file */
		dup2(stderrLogFile, STDERR_FILENO);

		/* TODO: Support redirection of both stdout and stderr to the same
		         file using pipe(2) */

		/* Execute the command */
		execl("%%JAVA_HOME%%/%%JAVA_CMD%%", "%%JAVA_HOME%%/%%JAVA_CMD%%", "-jar", %%JAVA_ARGS%% "%%JAR_FILE%%", %%JAR_ARGS%% NULL);

		fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to start %%APP_TITLE%% %%PORTVERSION%% since '%%JAVA_HOME%%/%%JAVA_CMD%% -jar %%JAR_FILE%%' in %%APP_HOME%%: ");
		perror(NULL);
	} else {
		printf(" [ DONE ]\n");
		writePID(file, pid);
	}
}

/**
 * Stops the daemon.
 */
void stop(void) {

	int file;
	int pid;

	/* Open and read the PID file */
	printf(">> Reading PID file (%%PID_FILE%%)...");
	file = openPIDFile();
	pid = readPID(file);

	printf(">> Checking if %%APP_TITLE%% %%PORTVERSION%% is running...");

	/* If there is a PID, see if the process still exists */
	if (pid != -1) {
		int result = kill(pid, 0);
		if (result != 0 && errno == ESRCH) {
			ftruncate(file, (off_t) 0);
			pid = -1;
		}
	}

	/* If there is no running process, produce an error */
	if (pid == -1) {
		printf(" [ FAILED ]\n");
		fprintf(stderr, "%%CONTROL_SCRIPT_NAME%%: %%APP_TITLE%% %%PORTVERSION%% is currently not running.\n");
		exit(ERR_NOT_RUNNING);
	}
	printf(" [ DONE ]\n");

	/* Terminate the process */
	killProcess(pid);

	/* Clear the PID file */
	ftruncate(file, (off_t) 0);
}


/**
 * Restarts the process. If it not currently running, then it will fail.
 */
void restart(void) {
	stop();
	start();
}
