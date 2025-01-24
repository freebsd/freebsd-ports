PORTNAME=	tmv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.76
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, intuitive linear algebra library for C++
WWW=		https://github.com/rmjarvis/tmv

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/TMV_LICENSE

USES=		gmake blaslapack:netlib localbase
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rmjarvis

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKEFILE=	${FILESDIR}/Makefile

OPTIONS_DEFINE=	DOCS

.if !exists(/usr/include/omp.h)
USES+=		compiler:gcc-c++11-lib
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/TMV_Documentation.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
