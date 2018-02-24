# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	dmg2img
PORTVERSION=	1.6.7
CATEGORIES=	sysutils
MASTER_SITES=	http://vu1tur.eu.org/tools/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	DMG2IMG convert tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ssl

PLIST_FILES=	bin/dmg2img \
		bin/vfdecrypt

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS = / s|$$| -I${OPENSSLINC}|; s| -lcrypto| -L${OPENSSLLIB}&|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dmg2img ${WRKSRC}/vfdecrypt ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
