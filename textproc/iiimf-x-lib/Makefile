# New ports collection makefile for:	iiimf-x-lib
# Date created:		8 Sep 2004
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	x-lib
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}-src-${IIIMF_VER}.tgz

MAINTAINER=	kcwu@csie.org
COMMENT=	Internet/Intranet Input Method X Client Framework

LIB_DEPENDS=	iiimp.0:${PORTSDIR}/textproc/iiimf-protocol-lib \
		iiimcf.2:${PORTSDIR}/textproc/iiimf-client-lib
RUN_DEPENDS=	${LOCALBASE}/csconv/csconv.so:${PORTSDIR}/textproc/iiimf-csconv

IIIMF_VER=	r12_0_1-svn1891
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}/iiimxcf/xiiimp.so
INSTALLS_SHLIB=	yes
USE_MOTIF=	yes
USE_REINPLACE=	yes
USE_OPENSSL=	yes
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_AUTOMAKE_VER=	19
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/../../acfiles/im_common.m4 \
		${WRKSRC}/configure.ac \
		${WRKSRC}/iiimp/iiimpAux.c \
		${WRKSRC}/iiimp/iiimpDL.c \
		${WRKSRC}/iiimp/iiimpIM.c \
		${WRKSRC}/iiimp/iiimpConv.c \
		${WRKSRC}/iiimp/csconv.h
.if ${OSVERSION} == 502010
	${REINPLACE_CMD} -e "s,-DARCH=[^ ]*,," \
		${WRKSRC}/../../acfiles/check_sys.m4
.endif

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal -I ../../acfiles
	${TOUCH} ${WRKSRC}/config.h.in

.include <bsd.port.post.mk>
