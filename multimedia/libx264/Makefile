# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#
# Updating notes: see multimedia/x264/Makefile.

PORTREVISION=	0
PKGNAMEPREFIX=	lib
COMMENT=	H.264/MPEG-4 AVC Video Encoding (Library)
MASTERDIR=	${.CURDIR}/../x264
PLIST=		${.CURDIR}/pkg-plist

# Clear dependency on libx264 (itself), see x264/Makefile
LIB_DEPENDS=	#

USES=		pathfix

OPTIONS_DEFINE=		ASM HI10P OPENCL
OPTIONS_DEFAULT=	ASM OPENCL
OPTIONS_EXCLUDE=	FFMS GPAC LAVF LSMASH SWSCALE

ASM_BUILD_DEPENDS=	${ASM_BUILD_DEPENDS_${ARCH}}
ASM_BUILD_DEPENDS_amd64=${ASM_BUILD_DEPENDS_i386}
ASM_BUILD_DEPENDS_i386=	nasm>=2.13:devel/nasm
ASM_CONFIGURE_ENABLE=	asm

HI10P_DESC=		Enable High 10 Profile 10-bit encoding
HI10P_CONFIGURE_ON=	--bit-depth=10

OPENCL_BUILD_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:devel/opencl
OPENCL_CONFIGURE_ENABLE=opencl

CONFIGURE_ARGS=		\
			--enable-static \
			--enable-shared \
			--disable-cli

PATHFIX_MAKEFILEIN=	Makefile

PLIST_FILES=	#
PLIST_SUB+=	X264_BUILD=${X264_BUILD}

pre-build:

.include "${MASTERDIR}/Makefile"
