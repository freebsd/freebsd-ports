# New ports collection makefile for:   gtk
# Version required:    971109
# Date Created:                28 Sep 1997
# Whom:                        Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.3 1997/11/13 09:08:35 tg Exp $
#

DISTNAME=      gtk+-971109
PKGNAME=       gtk-971109
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

.include <bsd.port.mk>
