PORTNAME=	btop
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.2
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Monitor of resources
WWW=		https://github.com/aristocratos/btop

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	aristocratos

MAKE_ARGS=	STRIP=true ADDFLAGS="${CXXFLAGS} ${LDFLAGS}" VERBOSE=true

.include <bsd.port.mk>
