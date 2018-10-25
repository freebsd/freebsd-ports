# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ssid
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Run a command in a new session

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PLIST_FILES=	bin/setsid bin/ssid

post-install:
	${LN} ${STAGEDIR}${PREFIX}/bin/ssid \
		${STAGEDIR}${PREFIX}/bin/setsid

.include <bsd.port.mk>
