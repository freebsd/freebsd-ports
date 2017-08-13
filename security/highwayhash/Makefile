# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	highwayhash
PORTVERSION=	g20170512
CATEGORIES=	security

MAINTAINER=	yuri@rawbw.com
COMMENT=	Fast strong hash functions: SipHash/HighwayHash

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 arm64 powerpc powerpc64
ONLY_FOR_ARCHS_REASON=	Assembly is implemented only for specific architectures in highwayhash/tsc_timer.h

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	2b666ae
USE_LDCONFIG=	yes

post-patch:
	# Install flags upstream issue: https://github.com/google/highwayhash/issues/58
	@${REINPLACE_CMD} -e '\
		s|LIBDIR|XLIBDIR|; \
		s| -O3||; \
		s|install -m0755 high|${INSTALL_DATA} high|; \
       		s|install -m0755 lib|${INSTALL_LIB} lib|' \
		${WRKSRC}/Makefile

post-install:
	# Symlink upstream issue: https://github.com/google/highwayhash/issues/57
	${RM} ${STAGEDIR}${PREFIX}/lib/libhighwayhash.so
	${LN} -s libhighwayhash.so.0 ${STAGEDIR}${PREFIX}/lib/libhighwayhash.so

.include <bsd.port.mk>
