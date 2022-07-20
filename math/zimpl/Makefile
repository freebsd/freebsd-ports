PORTNAME=	zimpl
DISTVERSION=	3.3.6
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://zimpl.zib.de/download/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language to translate the LP models into .lp or .mps

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	missing make/make.linux.$${arch}.gnu.opt for other architectures

BUILD_DEPENDS=	bison:devel/bison
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		cmake tar:tgz
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
