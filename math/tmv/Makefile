# $FreeBSD$

PORTNAME=	tmv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.75
PORTREVISION=	6
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, intuitive linear algebra library for C++

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/TMV_LICENSE

USES=		compiler:openmp gmake blaslapack:netlib localbase
USE_GITHUB=	yes
GH_ACCOUNT=	rmjarvis
USE_LDCONFIG=	yes

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKEFILE=	${FILESDIR}/Makefile

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/TMV_Documentation.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
