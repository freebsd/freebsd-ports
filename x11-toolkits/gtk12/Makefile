# New ports collection makefile for:   gtk
# Version required:		0.99.2
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.8 1998/01/21 12:26:45 asami Exp $
#

DISTNAME=      gtk+-0.99.3
PKGNAME=       gtk-0.99.3
CATEGORIES=    x11
MASTER_SITES=  ftp://ftp.gimp.org/pub/gtk/

MAINTAINER=    vanilla@FreeBSD.ORG

GNU_CONFIGURE= yes
USE_GMAKE=     yes
USE_X11=       yes

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
