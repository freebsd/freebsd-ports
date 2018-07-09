# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	highwayhash
PORTVERSION=	g20180626
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast strong hash functions: SipHash/HighwayHash

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to compile: /usr/lib/clang/5.0.0/include/mmintrin.h:47:5: use of undeclared identifier '__builtin_ia32_emms'
BROKEN_powerpc64=	fails to link: main.cpp.o: undefined reference to `boost::program_options::options_description::options_description
ONLY_FOR_ARCHS=		aarch64 amd64 powerpc powerpc64
ONLY_FOR_ARCHS_REASON=	Assembly is implemented only for specific architectures in highwayhash/tsc_timer.h

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	9099074
USE_LDCONFIG=	yes

# workaround for https://github.com/google/highwayhash/issues/69
MAKE_ARGS=	INCDIR=${PREFIX}/include XLIBDIR=${PREFIX}/lib

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
