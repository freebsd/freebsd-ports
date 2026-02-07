PORTNAME=	muparser
PORTVERSION=	2.3.5
DISTVERSIONPREFIX=	v
CATEGORIES=	math devel

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Mathematical expressions parser library written in C++
WWW=		https://beltoforion.de/en/muparser/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	beltoforion
USE_LDCONFIG=	yes

.if !exists(/usr/include/omp.h)
CMAKE_ARGS+=	-DENABLE_OPENMP:BOOL=OFF
.endif
CMAKE_OFF=	ENABLE_SAMPLES
PLIST_SUB=	MUPARSER_VERSION=${MUPARSER_VERSION}

OPTIONS_DEFINE=		EXAMPLES
EXAMPLES_PORTEXAMPLES=	*

MUPARSER_VERSION=	${PORTVERSION}

post-patch:
	${SED} -i.bak -e 's/%%MUPARSER_VERSION%%/${MUPARSER_VERSION}/' ${WRKSRC}/docs/Doxyfile

post-install-EXAMPLES-on:
	cd ${WRKSRC} && ${COPYTREE_SHARE} samples ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
