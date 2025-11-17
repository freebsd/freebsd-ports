PORTNAME=	radamsa
PORTVERSION=	0.7
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	General purpose fuzzer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	ol:lang/owl-lisp

USE_GITLAB=	yes
GL_ACCOUNT=	akihe
GL_TUPLE=	owl-lisp:hex:e95ebd38e4f7ef8e3d4e653f432e43ce0a804ca6:hex_dep/lib/hex

ALL_TARGET=	everything

PLIST_FILES=	bin/radamsa \
		share/man/man1/radamsa.1.gz

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${LN} -s ${LOCALBASE}/bin/ol ${WRKSRC}/bin/ol

post-patch:
	${REINPLACE_CMD} -e 's|PREFIX=/usr|PREFIX=${PREFIX}|' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/radamsa

.include <bsd.port.mk>
