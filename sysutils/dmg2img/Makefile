# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	dmg2img
PORTVERSION=	1.6.2
CATEGORIES=	sysutils
MASTER_SITES=	http://fbsd.zlonet.ru/distfiles/ \
		http://tourservice.kz/zloidemon/distfiles/ \
		http://z-up.ru/zloidemon/distfiles/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	DMG2IMG convert tool

PLIST_FILES=	bin/${PORTNAME} \
		bin/vfdecrypt

NO_STAGE=	yes
pre-configure:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}/bin|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
