# Created by: Ulrich Spoerlein <uspoerlein@gmail.com>
# $FreeBSD$

PORTNAME=	wmwifi
PORTVERSION=	0.4
DISTVERSIONSUFFIX=-bsd
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://digitalssg.net/debian/ \
		LOCAL/uqs

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	Dockapp displaying the signal strength of WiFi connection

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake localbase xorg
USE_XORG=	x11 xext xpm

CONFIGURE_ENV=	X_CFLAGS="${CFLAGS}"
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/wmwifi

.include <bsd.port.mk>
