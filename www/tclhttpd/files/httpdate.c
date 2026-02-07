/*
 * Produce time-stamp in the format suitable for HTTP's Date headers:
 *
 *	Date: Sun, 05 Nov 2006 16:18:01 GMT
 * and the Set-Cookie headers:
 *	Set-Cookie: .......; expires=Sun, 17-Jan-2038 19:14:07 GMT
 *
 * Although this can, of course, be done from TCL directly ([clock format]),
 * Tcl's method breaks, when the server is running in non-C locale.
 * Regardless of the locale, the Date-header must be in English and
 * this function takes care of that. Plus it is over 4 times faster...
 * Neither asctime() nor gmtime() would not work, because they
 * don't put a coma after the name of the weekday...
 *
 * Each command takes an optional argument specifying the date (in seconds
 * since epoch). If not specified, httpdate assumes the current date, and
 * the cookiedate -- a week from now.
 *
 * Written by Mikhail T. <mi+httpdate@aldan.algebra.com> in search of glory
 * but without ANY AND ALL WARRANTIES OR APPLICABILITIES FOR ANY PURPOSES.
 * Released into the wild under BSD license.
 *
 * Tested on FreeBSD-6.2 against Tcl-8.4. November 2006...
 */

#include <tcl.h>
#include <sys/time.h>
#include <errno.h>
#include <sys/limits.h>

/*
 * Using this method of copying short strings as integers instead of
 * relying on memcpy cuts the execution time from 3.53 microseconds to
 * 3.26 microseconds (or 8%) on my Opteron 275. Plus it is fun...
 * It is only safe, because the positions of both the month's name and
 * the weekday happen to be at 4-byte allignment, so the code is safe
 * from SIGBUS on all (?) known platforms...
 */
typedef union {
	char	string[4];
#if !defined(CHAR_BIT) || CHAR_BIT == 8
	int32_t	intrep;
#elif CHAR_BIT == 16
	int64_t	intrep;
#else
#	error "Unexpected or unknown value of CHAR_BIT on this system"
#endif
} fourcharstring;

static const fourcharstring months[] = {
	{ "Jan " }, { "Feb " }, { "Mar " }, { "Apr " }, { "May " }, { "Jun " },
	{ "Jul " }, { "Aug " }, { "Sep " }, { "Oct " }, { "Nov " }, { "Dec " }
};

static const fourcharstring weekdays[] = {
	{ "Sun," }, { "Mon," }, { "Tue," }, { "Wed," }, { "Thu," },
	{ "Fri," }, { "Sat," }
};

enum {
	HTTPDATE,
	COOKIEDATE
};

static int
httpdate(ClientData flavour, Tcl_Interp *I, int argc, Tcl_Obj *CONST objv[])
{
	union {
		fourcharstring	fields[7];
		char	date[30];
	} date;
	struct tm tm;
	time_t	tSec;
	Tcl_WideInt	wSec;

	switch (argc) {
	case 1:
		time(&tSec);
		if ((intptr_t)flavour == COOKIEDATE)
			/* Default for cookies is a week from now */
			tSec += 7*24*60*60;
		break;
	case 2:
		if (Tcl_GetWideIntFromObj(I, objv[1], &wSec) != TCL_OK)
			return TCL_ERROR;
		tSec = wSec;
		break;
	default:
		Tcl_WrongNumArgs(I, 1, objv, "?GMT-seconds?");
		return TCL_ERROR;
	}
	gmtime_r(&tSec, &tm);

	sprintf(date.date + 4, " %02d XXX %d %02d:%02d:%02d GMT",
	    tm.tm_mday, tm.tm_year + 1900, tm.tm_hour,
	    tm.tm_min, tm.tm_sec);
	
	/*
	 * Now deal with our 4-character strings
	 */
	date.fields[0].intrep = weekdays[tm.tm_wday].intrep;
	date.fields[2].intrep = months[tm.tm_mon].intrep;

	if ((intptr_t)flavour == COOKIEDATE)
		date.date[7] = date.date[11] = '-';

	Tcl_SetObjResult(I, Tcl_NewStringObj(date.date, 29));

	return TCL_OK;
}

int
Httpdate_Init(Tcl_Interp *I)
{
	Tcl_CreateObjCommand(I, "HttpdDate", httpdate, (void *)HTTPDATE, NULL);
	Tcl_CreateObjCommand(I, "cookiedate", httpdate, (void *)COOKIEDATE, NULL);

	return TCL_OK;
}
