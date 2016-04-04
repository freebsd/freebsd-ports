/* $FreeBSD$ */

/* dummy implementation of glibc functions needed by plugins */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

void
__assert_fail( const char *msg, const char *file, unsigned int line,
	       const char *func ) {
	fprintf( stderr, "Assertion failed: (%s), function %s, file %s, line %u\n",
		 msg, func, file, line );
	abort();
}

int
__fprintf_chk( FILE *fp, int flag, char const *format, ... ) {
	va_list ap;
	int res;

	va_start( ap, format );
	res = vfprintf( fp, format, ap );
	va_end( ap );
	return( res );
}

int
__printf_chk( int flag, char const *format, ... ) {
	va_list ap;
	int res;

	va_start( ap, format );
	res = vprintf( format, ap );
	va_end( ap );
	return( res );
}

int
__snprintf_chk( char *s, size_t maxlen, int flag, size_t slen,
		char const *format, ... ) {
	va_list ap;
	int res;

	va_start( ap, format );
	res = vsnprintf( s, maxlen, format, ap );
	va_end( ap );
	return( res );
}

char *
__strcpy_chk( char *dest, char const *src, size_t destlen ) {
	return( strcpy( dest, src ));
}

void
__syslog_chk( int priority, int flag, char const *format, ... ) {
	va_list ap;

	va_start( ap, format );
	vsyslog( priority, format, ap );
	va_end( ap );
}

#undef stderr
FILE *stderr;

static __attribute__(( constructor )) void
init_stderr( void ) {
	stderr = __stderrp;
}
