PORTNAME=	zimpl
DISTVERSIONPREFIX=	v
DISTVERSION=	3.8.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language to translate the LP models into .lp or .mps
WWW=		https://zimpl.zib.de \
		https://github.com/scipopt/zimpl

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bison:devel/bison
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		cmake tar:tgz
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	scipopt

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
