##################################################
#          The Exim mail transport agent         #
##################################################

# This is the template for Exim's main build-time configuration file. It 
# contains settings that are independent of any operating system. It should
# be edited and then saved to a file called Local/Makefile before first running
# the make command.

# Things that depend on the operating system have default settings in files
# called OS/Makefile-<osname>. These can be overridden by creating files
# called Local/Makefile-<osname>, though it is hoped that this will rarely
# be necessary.


# The binary directory: This variable defines where the exim binary will be
# installed by "make install" or "exim_install". It is also used internally
# by exim when it needs to re-invoke itself, either to send an error message,
# or to recover root privilege. Exim's utility binaries and scripts are also
# installed in this directory. There is no default for this variable built into 
# the source files; it must be set in one of the local configuration files.

BIN_DIRECTORY=/usr/local/bin


# The info directory: This variable defines where the exim info files will be
# installed by "make install" or "exim_install".

INFO_DIRECTORY=/usr/local/info


# The runtime configuration file: This variable defines where Exim's runtime
# configuration file is. There is no default built into the source files, so
# there must be a setting in one of the local configuration files. The 
# location of all other runtime files and directories can be changed in the 
# runtime configuration file.

CONFIGURE_FILE=/usr/local/etc/exim.conf


# The size of the delivery buffer: This specifies the size of buffer which is
# used when copying a message from the spool to a destination. The default 
# value built into the source is 8192.

# DELIVER_BUFFER_SIZE=8192


# Included directors: These variables determine which individual director
# drivers are included in the Exim binary. There are no defaults; those that
# are wanted must be defined here by setting the appropriate variables to the
# value "yes". The actions of each director are described in a separate chapter
# in the manual. Including a director in the binary does not cause it to
# be used automatically. It has also to be specified in the runtime 
# configuration file.

DIRECTOR_ALIASFILE=yes
DIRECTOR_FORWARDFILE=yes
DIRECTOR_LOCALUSER=yes
DIRECTOR_SMARTUSER=yes


# The mode of the database directory: Exim creates a directory called "db"
# in its spool directory, to hold its databases of hints. This variable
# determines the mode of the created directory. The default value in the 
# source is 0750.

# DB_DIRECTORY_MODE=0750


# Database locking: When trying to obtain a lock on one of its database files,
# there is a limit to the number of retries (default 10) and a time between
# retries (default 5 seconds). These can be altered here.

# DB_LOCK_RETRIES=10
# DB_LOCK_SLEEP=5


# Database file mode: The mode of files created in the "db" directory defaults
# to 0640 in the source, and can be changed here.

# DB_MODE=0640


# Running Exim not as root: A uid and gid for Exim can be specified here. These
# are compiled into the binary, but can be changed by settings in the runtime
# configuration file. The default in the code is -1, which means "unset" - 
# i.e. run as root unless specified otherwise at run time. Specifying 0 at 
# run time has the effect of unsetting any configured values.

# The settings here must be numeric; the run time file allows names to
# be used. When this uid and gid are set, the Exim binary still has to be
# setuid root if local deliveries are to be performed or a listener on port
# 25 is to be run, but it gives up its privilege when possible. There is a 
# trade-off between security and efficiency, controlled by the runtime 
# "security" setting, which controls how privilege is released (setuid vs 
# seteuid). The default value of -1 here means "unset".

# EXIM_GID=-1
# EXIM_UID=-1


# Compiling the Exim monitor: If you want to compile the Exim monitor,
# a program that requires an X11 display, then EXIM_MONITOR should be
# set to the value "eximon.bin". Comment out this setting to disable
# compilation of the binary file that is run by the eximon script. The
# locations of various X11 directories for libraries and include files 
# are defaulted in the OS/Makefile-Default file, and can be overridden
# in local OS-specific make files.

EXIM_MONITOR=eximon.bin


# The mode of the input directory: The input directory is where messages are
# kept while awaiting delivery. Exim creates it if necessary, using a mode
# which can be defined here (default 0750).

# INPUT_DIRECTORY_MODE=0750


# Exim log directory and files: Exim creates a directory called "log" inside
# its spool directory. The mode defaults to 0750, but can be changed here.
# The log files themselves are created with a default mode of 0640, but that
# can also be changed here.

# LOG_DIRECTORY_MODE=0750
# LOG_MODE=0640
           

# Per-message logs: While a message is in the process of being delivered,
# comments on its progress are written to a message log, for the benefit of
# human administrators. These logs are held in a directory called "msglog"
# in the spool directory. Its mode defaults to 0750, but can be changed here.
# The message log directory is also used for storing files that are used by
# transports for returning data to a message's sender (see the "return_output"
# option for transports).
            
# MSGLOG_DIRECTORY_MODE=0750


# Included routers: These variables determine which individual router drivers
# are included in the Exim binary. There are no defaults; those that are
# wanted must be defined here by setting the appropriate variables to the value
# "yes". The actions of each router are described in a separate chapter
# in the manual. Including a router in the binary does not cause it to
# be used automatically. It has also to be specified in the runtime 
# configuration file.

ROUTER_DOMAINLIST=yes
ROUTER_LOOKUPHOST=yes
ROUTER_QUERYPROGRAM=yes


# The spool directory: This directory is where all the data for messages in
# transit is kept. There is no default in the source, so its location must be
# defined in a local configuration file. Exim creates it if it does not exist,
# using the mode required for the sub-directory that it is trying to create at 
# the time. If a non-root uid and gid have been defined for Exim (either in 
# this configuration file, or by the runtime configuration options), then this 
# directory and all sub-directories and their files will be created with their
# owners and groups set to Exim's uid and gid.

# Many installations will want something like this
SPOOL_DIRECTORY=/var/spool/exim

# Others may prefer to keep all Exim things under one directory
# SPOOL_DIRECTORY=/usr/exim/spool


# If Exim creates the spool directory, it is given this mode, defaulting in the 
# source to 0750.

# SPOOL_DIRECTORY_MODE=0750


# The mode of files on the input spool which hold the contents of message can
# be changed here. The default is 0600. If you have defined a uid and gid for
# Exim and want information from the spool to be available to anyone who is a 
# member of the Exim group, change the value to 0640. This is particularly
# relevant if you are going to run the Exim monitor.

# SPOOL_MODE=0600


# If STDERR_FILE is defined then the -df command line option causes Exim to
# redirect stderr to the named file. This is useful for catching debugging
# output when starting Exim via inetd. 

# STDERR_FILE=


# Included transports: These variables determine which individual transport
# drivers are included in the Exim binary. There are no defaults; those that
# are wanted must be defined here by setting the appropriate variables to the
# value "yes". The actions of each transport are described in a separate chapter
# in the manual. Including a transport in the binary does not cause it to
# be used automatically. It has also to be specified in the runtime 
# configuration file.

TRANSPORT_APPENDFILE=yes
TRANSPORT_PIPE=yes
TRANSPORT_SMTP=yes

# The Debug transport is special, and should be included only when low-level
# debugging is being performed. In conjunction with the "debug_transport"
# configuration option, it permits the subversion of all mail deliveries to
# a given file.

# TRANSPORT_DEBUG=

# End of EDITME
