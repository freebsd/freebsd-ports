/* Ftools info: $Header: /software/lheasoft/lheavc/ftools_42/src/ftoolslib/unx/gttime.c,v 1.1 1998/06/26 03:19:14 guerber Exp $ */
/***************************************************************************
 * 
 *  gttime: Get current system time, returning hours, minutes, and seconds
 *          as integers.  Time will be UTC if available, else local.
 *
 *  This is a reimplementation of /library/utilties/unx/gttime.f, reading
 *  the standard C time structure instead of calling xanlib's gettim, which
 *  uses the system-dependent fdate() call.
 *
 *  To get the system date as integers, use the Cfitsio routine ffgsdt/ftgsdt.
 *
 *  AUTHOR:  Jeff Guerber, Raytheon STX / NASA-GSFC, June 25, 1998.
 *  Based largely on the cfitsio function ffgsdt().
 *
 *  MODIFICATION HISTORY:
 *  $Log: gttime.c,v $
 * Revision 1.1  1998/06/26  03:19:14  guerber
 * Get system time, returning integers. Replaces library/utilities/unx/gttime.f.
 *
 *
 ***************************************************************************/

/***************************************************************************
 * $FreeBSD$
 * Downloaded by thierry@FreeBSD.org on Nov. 22 2012
 * from ftp://legacy.gsfc.nasa.gov/software/ftools/release/FTools_4.2/ftools_42/src/ftoolslib/unx/gttime.c
 * See http://heasarc.gsfc.nasa.gov/docs/software/ftools/ftools_menu.html
 * FV License Agreement: http://heasarc.gsfc.nasa.gov/docs/software/ftools/fv/doc/license.html
 *
 ***************************************************************************/
#include <stdio.h>
#include <time.h>
#include <cfortran.h>

void gttime( int *hr, int *min, int *sec )
{
  time_t sysclk;
  struct tm *timep;

  sysclk = time( NULL );
  timep = gmtime( &sysclk );

  if ( timep == NULL ) {     /* UTC isn't available so use local time */
      timep = localtime( &sysclk );
  }

  *hr = timep->tm_hour;
  *min = timep->tm_min;
  *sec = timep->tm_sec;

  return;
}

FCALLSCSUB3(gttime,GTTIME,gttime,PINT,PINT,PINT)
