PORTNAME=	fastops
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	AVX/AVX2-accelerated bulk call of math functions

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	uses AVX and AVX2 instructions

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	yandex

do-test:
	${TEST_WRKSRC}/${PORTNAME}/ut/${PORTNAME}_test

post-stage:
# Rename generically-named binaries to avoid potential clashes
.for p in benchmark eval
	${MV} ${STAGEDIR}${PREFIX}/bin/${p} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}_${p}
.endfor
# Remove the test program (we run tests, but not install them)
	${RM} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}_test

.include <bsd.port.mk>
