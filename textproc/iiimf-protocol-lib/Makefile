# New ports collection makefile for:	iiimf-protocol-lib
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	protocol-lib
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}-src-${IIIMF_VER}.tgz

MAINTAINER=	kcwu@csie.org
COMMENT=	Internet/Intranet Input Method Framework protocol library

IIIMF_VER=	r12_0_1-svn1891
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}/lib/iiimp
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
USE_OPENSSL=	yes
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_AUTOMAKE_VER=	19
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/iiimf/iiimp

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/../../acfiles/im_common.m4 \
		${WRKSRC}/configure.ac

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal -I ../../acfiles
	${TOUCH} ${WRKSRC}/config.h.in

.include <bsd.port.mk>
