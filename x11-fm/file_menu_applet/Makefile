# New ports collection makefile for:	file_menu_applet
# Date created:				4 May 2002
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	file_menu_applet
PORTVERSION=	0.5
CATEGORIES=	x11-fm gnome
MASTER_SITES=	http://www.zoned.net:8000/~xkahn/file_menu_applet/

MAINTAINER=	klammer@webonaut.com

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack libpanel gnomevfs libglade
GNU_CONFIGURE=	yes

pre-everything::
	@${SH} ${PKGINSTALL} ${PKGNAME} ${PREFIX}

.include <bsd.port.mk>
