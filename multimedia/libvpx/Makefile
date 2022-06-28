# Created by: Ashish SHUKLA <ashish@FreeBSD.org>

PORTNAME=	libvpx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.0
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	VP8/VP9 reference encoder/decoder

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
BUILD_DEPENDS_armv6=	as:devel/binutils
BUILD_DEPENDS_armv7=	as:devel/binutils
BUILD_DEPENDS_i386=	nasm:devel/nasm

USE_GITHUB=	yes
GH_ACCOUNT=	webmproject

USES=		compiler:c++11-lib cpe gmake perl5 shebangfix
CPE_VENDOR=	webmproject
HAS_CONFIGURE=	yes
USE_PERL5=	build
USE_LDCONFIG=	yes
SHEBANG_FILES=	build/make/ads2gas.pl
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--disable-install-docs \
		--disable-install-srcs \
		--disable-unit-tests \
		--enable-multi-res-encoding \
		--enable-pic \
		--enable-shared \
		--enable-vp9-highbitdepth \
		--enable-vp9-postproc \
		--enable-vp9-temporal-denoising \
		--size-limit=16384x16384
MAKE_ARGS+=	verbose=yes
ALL_TARGET=	# empty

post-patch:
	@${REINPLACE_CMD} -E '/gcctarget|link_with_cc/s/gcc[[:>:]]/$${CC}/' \
		${WRKSRC}/build/make/configure.sh
# Extract (snapshot) version from the port instead of CHANGELOG
	@${REINPLACE_CMD} '/^git_version_id/s/""/"${DISTVERSIONFULL}"/' \
		${WRKSRC}/build/make/version.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vpx*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvpx.so.*.*.*

.include <bsd.port.mk>
