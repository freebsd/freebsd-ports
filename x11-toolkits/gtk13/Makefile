# New ports collection makefile for:   gtk
# Version required:    970925
# Date Created:                28 Sep 1997
# Whom:                        Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id$
#

DISTNAME=      gtk+970925
PKGNAME=       gtk-970925
CATEGORIES=    x11
MASTER_SITES=  ftp://ftp.gimp.org/pub/gtk/

MAINTAINER=    vanilla@MinJe.com.TW

GNU_CONFIGURE= yes
USE_GMAKE=     yes
USE_X11=       yes

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

.include <bsd.port.mk>
