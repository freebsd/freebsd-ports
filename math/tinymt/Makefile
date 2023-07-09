PORTNAME=	tinymt
PORTVERSION=	1.1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tiny Mersenne Twister
WWW=		https://github.com/MersenneTwister-Lab/TinyMT

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

WRKSRC_SUBDIR=	tinymt

PLIST_FILES=	bin/tinymt-check32 \
		bin/tinymt-check64 \
		include/tinymt32.h \
		include/tinymt64.h

USE_GITHUB=	yes
GH_ACCOUNT=	MersenneTwister-Lab
GH_PROJECT=	TinyMT

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/check32 ${STAGEDIR}${PREFIX}/bin/tinymt-check32
	${INSTALL_PROGRAM} ${WRKSRC}/check64 ${STAGEDIR}${PREFIX}/bin/tinymt-check64
	${INSTALL_DATA} ${WRKSRC}/tinymt32.h ${WRKSRC}/tinymt64.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
