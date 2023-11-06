PORTNAME=	mutationpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.6dev2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MUlticomponent Thermodynamic And Transport library for IONized gases
WWW=		https://github.com/mutationpp/Mutationpp

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	catch>0:devel/catch

USES=		cmake:testing eigen:3

USE_GITHUB=	yes
GH_PROJECT=	Mutationpp

#CXXFLAGS+=	-I${LOCALBASE}/include/catch2

CMAKE_TESTING_ON=	ENABLE_TESTING # tests fail to compile, see https://github.com/mutationpp/Mutationpp/issues/244, https://github.com/mutationpp/Mutationpp/issues/245

.include <bsd.port.mk>
