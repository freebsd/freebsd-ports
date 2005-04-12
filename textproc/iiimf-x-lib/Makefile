# New ports collection makefile for:	iiimf-x-lib
# Date created:		8 Sep 2004
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	x-lib
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk-src-${IIIMF_VER}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kcwu@csie.org
COMMENT=	Internet/Intranet Input Method X Client Framework

LIB_DEPENDS=	iiimp.0:${PORTSDIR}/textproc/iiimf-protocol-lib \
		iiimcf.2:${PORTSDIR}/textproc/iiimf-client-lib
RUN_DEPENDS=	${LOCALBASE}/lib/im/csconv/csconv.so:${PORTSDIR}/textproc/iiimf-csconv

IIIMF_VER=	r12_1-svn2002
USE_BZIP2=	yes
USE_REINPLACE=  yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_MOTIF=      yes
USE_OPENSSL=    yes
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_AUTOMAKE_VER=	19
WANT_LIBTOOL_VER=	15

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=         ${WRKDIR}/${DISTNAME:S/src-//}/iiimxcf/xiiimp.so
PATCH_WRKSRC=   ${WRKDIR}/${DISTNAME:S/src-//}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=         "It is supported on FreeBSD 5.3 and later"
.endif

.if ${ARCH} != "i386"
IGNORE=	"${ARCH} is not support."
.endif

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -lintl ${PTHREAD_LIBS}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
UPDATE_ARGS+=	ACLOCAL=${ACLOCAL} AUTOMAKE=${AUTOMAKE} \
		AUTOHEADER=${AUTOHEADER} AUTOCONF=${AUTOCONF} \
		LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE} \
		ACLOCAL_DIR="-I ${LOCALBASE}/share/aclocal -I ${ACLOCAL_DIR}"

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/../../acfiles/im_common.m4

pre-configure:
	@cd ${WRKSRC}/../.. && ${GMAKE} ${UPDATE_ARGS} update-acfiles
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} \
	 -I ../../acfiles -I ${LOCALBASE}/share/aclocal -I ${ACLOCAL_DIR}
	@cd ${WRKSRC} && ${REINPLACE_CMD} \
	 -e "s^\$$ac_aux_dir/ltconfig^${LTCONFIG}^g" \
	 -e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LTMAIN}^g" \
	 -e '/^LIBTOOL=/s^\$$(top_builddir)/libtool^${LIBTOOL}^g' \
	 ${LIBTOOLFILES}
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOHEADER}

.include <bsd.port.post.mk>
