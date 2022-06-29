PORTNAME=	btop
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.7
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Monitor of resources

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	aristocratos

CXXFLAGS_i386=	-latomic
CXXFLAGS_powerpc=	-latomic
MAKE_ARGS=	STRIP=true ADDFLAGS="${CXXFLAGS} ${LDFLAGS}"

.include <bsd.port.mk>
