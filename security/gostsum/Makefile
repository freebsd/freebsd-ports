PORTNAME=	gostsum
PORTVERSION=	20221213
CATEGORIES=	security

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Implementation of GOST R 34.11-94, GOST R 34.11-2012 hash functions

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	AnatolyGeorgievski
GH_TAGNAME=	b1a7a8e33ade59d43147a2f2531fe87c26de4093

PLIST_FILES=	bin/gostsum

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|CC   =.*||g' \
		-e 's|CFLAGS =.*||g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gostsum ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
