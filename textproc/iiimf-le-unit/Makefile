# New ports collection makefile for:	iiimf-le-unit
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	le-unit
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}-src-${IIIMF_VER}.tgz

MAINTAINER=	kcwu@csie.org
COMMENT=	IIIMF UNIcode Table based generic composition engine

RUN_DEPENDS=	${LOCALBASE}/lib/im/htt:${PORTSDIR}/textproc/iiimf-server

IIIMF_VER=	r12_0_1-svn1891
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}/leif
BUILD_WRKSRC=	${WRKSRC}/unit
INSTALL_WRKSRC=	${WRKSRC}/unit
USE_ICONV=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_AUTOMAKE_VER=	19
USE_LIBTOOL_VER=	15
AUTOMAKE_ARGS=	--add-missing --copy --gnu
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not build on FreBSD 4.x because of missing fputwc() function in libc
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
BROKEN=		"Segfault during build on amd64 and ia64"
.endif

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/../acfiles/im_common.m4 \
		${WRKSRC}/configure.ac \
		${WRKSRC}/unit/include/unit_input.h \
		${WRKSRC}/unit/phonetic_im/phonetic_im.c

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal -I ../acfiles
	${TOUCH} ${WRKSRC}/config.h.in
	cd ${WRKSRC} && ${LIBTOOLIZE} --copy --force --automake

.include <bsd.port.post.mk>
