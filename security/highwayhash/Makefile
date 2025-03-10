PORTNAME=	highwayhash
PORTVERSION=	g20240418
PORTEPOCH=	1
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast strong hash functions: SipHash/HighwayHash
WWW=		https://github.com/google/highwayhash

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	assembly is implemented only for specific architectures in highwayhash/tsc_timer.h

USES=		compiler:c++11-lang gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	f8381f3

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*}
CXXFLAGS+=	-mpower8-vector
MAKE_ENV+=	HH_POWER=1
.elif ${ARCH} == aarch64 || ${ARCH:Marmv*}
MAKE_ENV+=	HH_ARM=1
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libhighwayhash.so

.include <bsd.port.mk>
