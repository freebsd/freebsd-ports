# New ports collection makefile for:	net/wmwifi
# Date created:				01.07.2005
# Whom:					Ulrich Spoerlein <uspoerlein@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	wmwifi
PORTVERSION=	0.4
DISTVERSIONSUFFIX=-bsd
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://digitalssg.net/debian/ \
		http://people.freebsd.org/~uqs/distfiles/

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	Dockapp displaying the signal strength of WiFi connection

GNU_CONFIGURE=	yes
USE_XORG=	x11 xpm
USE_GMAKE=	yes

CONFIGURE_ENV+=	"CPPFLAGS=-I${LOCALBASE}/include"

PLIST_FILES=	bin/wmwifi

.include <bsd.port.mk>
