PORTNAME=	ncrystal
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.6
CATEGORIES=	science # physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for thermal neutron transport in crystals and other materials
WWW=		https://github.com/mctools/ncrystal

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing python:build shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mctools

SHEBANG_FILES=	tests/scripts/*

CMAKE_TESTING_ON=	NCRYSTAL_ENABLE_TESTING \
			NCRYSTAL_ENABLE_CORE_TEST

post-install: # workaround for https://github.com/mctools/ncrystal/issues/150
	@${RM} ${STAGEDIR}${PREFIX}/*.sh

# tests as of 4.2.6: 52% tests passed, 42 tests failed out of 87

.include <bsd.port.mk>
