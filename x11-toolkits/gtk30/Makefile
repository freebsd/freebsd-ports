# New ports collection makefile for:   gtk
# Version required:		1.0.2
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.16 1998/05/06 09:46:24 vanilla Exp $
#

DISTNAME=      gtk+-1.0.2
PKGNAME=       gtk-1.0.2
CATEGORIES=    x11
MASTER_SITES=  ftp://ftp.gimp.org/pub/gtk/v1.0/

MAINTAINER=    vanilla@FreeBSD.ORG

GNU_CONFIGURE= yes
USE_GMAKE=     yes
USE_X11=       yes

CONFIGURE_ENV= INSTALL='/usr/bin/install -c'

MAN1=		gtk-config.1

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
