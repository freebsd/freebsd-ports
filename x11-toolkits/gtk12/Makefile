# New ports collection makefile for:   gtk
# Version required:		0.99.10
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.13 1998/04/04 13:46:25 vanilla Exp $
#

DISTNAME=      gtk+-0.99.10
PKGNAME=       gtk-0.99.10
CATEGORIES=    x11
MASTER_SITES=  ftp://ftp.gimp.org/pub/gtk/v0.99/

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
