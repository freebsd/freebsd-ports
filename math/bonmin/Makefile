PORTNAME=	bonmin
DISTVERSIONPREFIX=	releases/
DISTVERSION=	1.8.8
PORTREVISION=	1
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Basic Open-source Nonlinear Mixed INteger programming

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/Bonmin/LICENSE

LIB_DEPENDS=	libCbc.so:math/cbc \
		libipopt.so:math/ipopt

USES=		blaslapack:netlib compiler:c++11-lang gmake libtool pkgconfig
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	Bonmin
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

TEST_TARGET=	test

.include <bsd.port.mk>
