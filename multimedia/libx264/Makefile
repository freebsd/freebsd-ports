# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#
# Updating notes: see multimedia/x264/Makefile.

PKGNAMEPREFIX=	lib
COMMENT=	H.264/MPEG-4 AVC Video Encoding (Library)
MASTERDIR=	${.CURDIR}/../x264
PLIST=		${.CURDIR}/pkg-plist

USES=		gmake pathfix tar:bzip2

OPTIONS_DEFINE=		ASM DEBUG GCC HI10P PGO
OPTIONS_EXCLUDE=	GPAC LAV

DEBUG_CONFIGURE_OFF=	--enable-strip

HI10P_DESC=		Enable High 10 Profile 10-bit encoding
HI10P_CONFIGURE_ON=	--bit-depth=10

CONFIGURE_ARGS=		${CONFIGURE_COMMON_ARGS} \
			--enable-static \
			--enable-shared \
			--disable-cli

PATHFIX_MAKEFILEIN=	Makefile

PLIST_SUB+=	X264_BUILD=${X264_BUILD}

.include "${MASTERDIR}/Makefile"
