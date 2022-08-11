PORTNAME=	muparser
PORTVERSION=	2.3.2
DISTVERSIONPREFIX=	v
CATEGORIES=	math devel

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Mathematical expressions parser library written in C++

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	beltoforion

OPTIONS_DEFINE=		EXAMPLES

CMAKE_OFF=	ENABLE_SAMPLES

EXAMPLES_PORTEXAMPLES=	*

.if !exists(/usr/include/omp.h)
CMAKE_ARGS+=	-DENABLE_OPENMP:BOOL=OFF
.endif

post-install-EXAMPLES-on:
	cd ${WRKSRC} && ${COPYTREE_SHARE} samples ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
