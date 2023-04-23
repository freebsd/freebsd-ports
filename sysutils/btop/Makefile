PORTNAME=	btop
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.13
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Monitor of resources
WWW=		https://github.com/aristocratos/btop

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	aristocratos

CXXFLAGS_i386=	-latomic
CXXFLAGS_powerpc=	-latomic
MAKE_ARGS=	STRIP=true ADDFLAGS="${CXXFLAGS} ${LDFLAGS}" VERBOSE=true

.include <bsd.port.mk>
