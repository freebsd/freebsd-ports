# New ports collection makefile for:	iiimf-x
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	iiimf-x
PORTVERSION=	${IIIMF_VER:S/_/./:C/-.*//}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/docs/im-sdk/
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}.${IIIMF_VER:S/-/./}${EXTRACT_SUFX}

MAINTAINER=	kcwu@csie.org
COMMENT=	Internet/Intranet Input Method X Client Framework

LIB_DEPENDS=	iiimp.0:${PORTSDIR}/textproc/iiimf-protocol-lib \
		iiimcf.2:${PORTSDIR}/textproc/iiimf-client-lib

IIIMF_VER=	r11_4-1467
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
USE_MOTIF=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
DIRS=		iiimxcf/xiiimp.so iiimxcf/htt_xbe

post-patch:
.for DIR in ${DIRS}
	${REINPLACE_CMD} -e "s,-lpthread,-pthread,g" \
		-e "s,-D_POSIX_C_SOURCE=199506L,,g" \
		-e "s,has_xiccallback=no,has_xiccallback=yes,g" \
		-e "s,/usr/lib/im,${LOCALBASE}/lib/im,g" \
		-e "s,-I\$$(IM_INCLUDEDIR),-I${LOCALBASE}/include/iiimf,g" \
		${WRKSRC}/${DIR}/configure
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/iiimxcf/xiiimp.so/iiimp/Makefile.in \
		${WRKSRC}/iiimxcf/xiiimp.so/iiimp/iiimpAux.c \
		${WRKSRC}/iiimxcf/xiiimp.so/iiimp/iiimpIM.c \
		${WRKSRC}/iiimxcf/xiiimp.so/iiimp/iiimpConv.c \
		${WRKSRC}/iiimxcf/xiiimp.so/iiimp/csconv.h \
		${WRKSRC}/iiimxcf/htt_xbe/lib/IMdkit/common/XIMPublic.cpp \
		${WRKSRC}/iiimxcf/htt_xbe/src/watchdog.c
.endfor

do-configure:
.for DIR in ${DIRS}
	cd ${WRKSRC}/${DIR} && ${SH} configure ${CONFIGURE_ARGS}
.endfor

do-build:
.for DIR in ${DIRS}
	cd ${WRKSRC}/${DIR} && ${GMAKE} all
.endfor

do-install:
.for DIR in ${DIRS}
	cd ${WRKSRC}/${DIR} && ${GMAKE} install
.endfor

.include <bsd.port.mk>
