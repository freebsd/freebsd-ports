# New ports collection makefile for:	iiimf-server
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	server
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}-src-${IIIMF_VER}.tgz

MAINTAINER=	kcwu@csie.org
COMMENT=	Internet/Intranet Input Method Server Framework

LIB_DEPENDS=	iiimp.0:${PORTSDIR}/textproc/iiimf-protocol-lib

IIIMF_VER=	r12_0_1-svn1891
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}/iiimsf
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}-${IIIMF_VER}
USE_OPENSSL=	yes
USE_REINPLACE=	yes
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_AUTOMAKE_VER=	19
USE_LIBTOOL_VER=	15
LIBTOOLFILES=	${WRKSRC}/aclocal.m4
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not build on sparc64"
.endif

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/../acfiles/im_common.m4 \
		${WRKSRC}/configure.ac \
		${WRKSRC}/src/IMSvrCfg.cpp \
		${WRKSRC}/src/watchdog.c

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal -I ../acfiles
	${TOUCH} ${WRKSRC}/config.h.in

.include <bsd.port.post.mk>
