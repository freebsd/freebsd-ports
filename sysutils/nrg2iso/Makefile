# Created by: dieringe
# $FreeBSD$

PORTNAME=	nrg2iso
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://gregory.kokanosky.free.fr/v4/linux/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Nero .nrg CD-Image format to ISO

USES=		gmake

PLIST_FILES=	bin/nrg2iso

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|gcc|${CC} ${CFLAGS}|' \
		${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/nrg2iso ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
