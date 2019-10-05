# $FreeBSD$

PORTNAME=	gemmlowp
DISTVERSION=	g20190812
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Low-precision matrix multiplication library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	dc69acd

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
.for dir in public fixedpoint eight_bit_int_gemm internal profiling meta
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
.endfor
	@${FIND} ${STAGEDIR} -name "*.cc" -delete

.include <bsd.port.mk>
