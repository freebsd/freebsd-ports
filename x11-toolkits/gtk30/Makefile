# New ports collection makefile for:   gtk
# Version required:		1.0.1
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.15 1998/04/17 13:21:17 erich Exp $
#

DISTNAME=      gtk+-1.0.1
PKGNAME=       gtk-1.0.1
CATEGORIES=    x11
MASTER_SITES=  ftp://ftp.gimp.org/pub/gtk/v1.0/

MAINTAINER=    vanilla@FreeBSD.ORG

GNU_CONFIGURE= yes
USE_GMAKE=     yes
USE_X11=       yes

CONFIGURE_ENV= INSTALL='/usr/bin/install -c'

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
