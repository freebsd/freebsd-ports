# New ports collection makefile for:	iiimf-server
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	server
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk-src-${IIIMF_VER}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kcwu@csie.org
COMMENT=	Internet/Intranet Input Method Server Framework

LIB_DEPENDS=    iiimp.0:${PORTSDIR}/textproc/iiimf-protocol-lib

IIIMF_VER=	r12_1-svn2002
USE_RC_SUBR=	htt.sh
USE_BZIP2=	yes
USE_REINPLACE=  yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig libxml2
USE_OPENSSL=    yes
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_AUTOMAKE_VER=	19
WANT_LIBTOOL_VER=	15

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=         ${WRKDIR}/${DISTNAME:S/src-//}/iiimsf
PATCH_WRKSRC=   ${WRKDIR}/${DISTNAME:S/src-//}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=         "It is supported on FreeBSD 5.3 and later"
.endif

.if ${ARCH} != "i386"
IGNORE=	"${ARCH} is not support."
.endif

.if defined(WITH_DEBUG)
CFLAGS+=	-g -ggdb -DDEBUG
.endif

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
UPDATE_ARGS+=	ACLOCAL=${ACLOCAL} AUTOMAKE=${AUTOMAKE} \
		AUTOHEADER=${AUTOHEADER} AUTOCONF=${AUTOCONF} \
		LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE} \
		ACLOCAL_DIR="-I ${LOCALBASE}/share/aclocal -I ${ACLOCAL_DIR}"

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/../acfiles/im_common.m4 \
		${WRKSRC}/src/le.xml.conf
	${MV} ${WRKSRC}/htt.xml.conf ${WRKSRC}/htt.xml.conf.sample
	${MV} ${WRKSRC}/src/le.xml.conf ${WRKSRC}/src/le.xml.conf.sample

pre-configure:
	@cd ${WRKSRC}/.. && ${GMAKE} ${UPDATE_ARGS} update-acfiles
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} \
	 -I ../acfiles -I ${LOCALBASE}/share/aclocal -I ${ACLOCAL_DIR}
	@cd ${WRKSRC} && ${REINPLACE_CMD} \
	 -e "s^\$$ac_aux_dir/ltconfig^${LTCONFIG}^g" \
	 -e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LTMAIN}^g" \
	 -e '/^LIBTOOL=/s^\$$(top_builddir)/libtool^${LIBTOOL}^g' \
	 ${LIBTOOLFILES}
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOHEADER}

post-configure:
	${REINPLACE_CMD} -e "s,\$${prefix}/var,/var,g" \
		${WRKSRC}/src/Makefile

.include <bsd.port.post.mk>
