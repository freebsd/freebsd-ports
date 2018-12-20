# $FreeBSD$

PORTNAME=	agrum
DISTVERSION=	0.13.4
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

CMAKE_OFF=	BUILD_PYTHON USE_SWIG

.include <bsd.port.mk>
