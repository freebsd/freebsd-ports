PORTNAME=	btop
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
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

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1302507
USE_GCC=	yes
.if ${ARCH} == i386 || ${ARCH} == powerpc
LDFLAGS+=	-latomic
.endif
.endif

.include <bsd.port.mk>
