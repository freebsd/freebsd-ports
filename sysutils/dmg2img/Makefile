PORTNAME=	dmg2img
PORTVERSION=	1.6.7
CATEGORIES=	sysutils
MASTER_SITES=	http://vu1tur.eu.org/tools/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	DMG2IMG convert tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe ssl

PLIST_FILES=	bin/dmg2img \
		bin/vfdecrypt

CPE_VENDOR=	dmg2img_project

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS = / s|$$| -I${OPENSSLINC}|; s| -lcrypto| -L${OPENSSLLIB}&|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dmg2img ${WRKSRC}/vfdecrypt ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
