PORTNAME=	lmfit
DISTVERSION=	10.0
CATEGORIES=	math
MASTER_SITES=	https://jugit.fz-juelich.de/mlz/${PORTNAME}/-/archive/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-v${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for Levenberg-Marquardt minimization and least-squares fitting
WWW=		https://jugit.fz-juelich.de/mlz/lmfit

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libheinz>0:devel/libheinz

USES=		cmake:testing perl5
USE_PERL5=	build # only for pod2html
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

# tests as of 10.0 fail: 100% tests passed, 0 tests failed out of 3

.include <bsd.port.mk>
