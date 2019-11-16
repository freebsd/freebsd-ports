# $FreeBSD$

PORTNAME=	clingo
DISTVERSIONPREFIX=	v
DISTVERSION=	5.4.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Grounder and solver for logic programs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	re2c:devel/re2c

USES=		cmake compiler:c++14-lang
USE_GITHUB=	yes
GH_ACCOUNT=	potassco
GH_TUPLE=	potassco:clasp:c183473:clasp/clasp
USE_LDCONFIG=	yes

CMAKE_OFF=	CLINGO_BUILD_WITH_PYTHON # broken, see https://github.com/potassco/clingo/issues/178
CMAKE_OFF+=	CLINGO_BUILD_WITH_LUA

.include <bsd.port.mk>
