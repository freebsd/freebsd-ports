# $FreeBSD$

PORTNAME=	agrum
DISTVERSION=	0.13.4
PORTREVISION=	1
CATEGORIES=	science math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical modeler for Bayesian networks, influence diagrams, etc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource compiler:c++17-lang
USE_GITLAB=	yes
GL_SITE=	https://gitlab.com
GL_ACCOUNT=	agrumery
GL_PROJECT=	aGrUM
GL_COMMIT=	7fb897064bd26e2844164bad191c97173c71262e
USE_LDCONFIG=	yes

CMAKE_OFF=	USE_SWIG

OPTIONS_DEFINE=		ODBC PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

ODBC_USES=		localbase:ldflags
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC

PYTHON_CMAKE_BOOL=	BUILD_PYTHON
PYTHON_USES=		python

post-patch-ODBC-off: # https://gitlab.com/agrumery/aGrUM/issues/22
	@${REINPLACE_CMD} 's|include(Nanodbc.agrum)|#&|' ${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
