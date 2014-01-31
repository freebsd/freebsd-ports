# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	dmg2img
PORTVERSION=	1.6.5
CATEGORIES=	sysutils
MASTER_SITES=	http://vu1tur.eu.org/tools/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	DMG2IMG convert tool

PLIST_FILES=	bin/${PORTNAME} \
		bin/vfdecrypt

pre-configure:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${STAGEDIR}${PREFIX}/bin|g' \
		${WRKSRC}/Makefile
post-build:
	${MAKE} -C ${WRKSRC} install

.include <bsd.port.mk>
