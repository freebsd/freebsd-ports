# New ports collection makefile for:	net/wmwifi
# Date created:				01.07.2005
# Whom:					Ulrich Spoerlein <q@galgenberg.net>
#
# $FreeBSD$
#

PORTNAME=	wmwifi
PORTVERSION=	0.4
DISTVERSIONSUFFIX=-bsd
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://digitalssg.net/debian/

MAINTAINER=	uqs@spoerlein.net
COMMENT=	Dockapp displaying the signal strength of WiFi connection

GNU_CONFIGURE=	yes
USE_XORG=	x11 xpm
USE_GMAKE=	yes

CONFIGURE_ENV+=	"CPPFLAGS=-I${LOCALBASE}/include"

PLIST_FILES=	bin/wmwifi

.include <bsd.port.mk>
