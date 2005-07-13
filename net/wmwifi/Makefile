# New ports collection makefile for:	net/wmwifi
# Date created:				01.07.2005
# Whom:					Ulrich Spoerlein <q@galgenberg.net>
#
# $FreeBSD$
#

PORTNAME=	wmwifi
PORTVERSION=	0.4
PORTREVISION=	1
DISTVERSIONSUFFIX=-bsd
CATEGORIES=	net
MASTER_SITES=	http://digitalssg.net/debian/

MAINTAINER=	q@galgenberg.net
COMMENT=	Dockapp displaying the signal strength of WiFi connection

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV+=	"CPPFLAGS=-I${X11BASE}/include"

PLIST_FILES=	bin/wmwifi

.include <bsd.port.mk>
