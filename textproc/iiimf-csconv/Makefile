# New ports collection makefile for:	iiimf-csconv
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	csconv
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk-src-${IIIMF_VER}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kcwu@csie.org
COMMENT=	Internet/Intranet Input Method Framework encoding convert library

IIIMF_VER=	r12_1-svn2002
USE_BZIP2=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_GNOME=	intltool
USE_REINPLACE=	yes
USE_AUTOCONF_VER=	259
#USE_AUTOHEADER_VER=	259
WANT_AUTOMAKE_VER=	19
WANT_LIBTOOL_VER=	15

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}/lib/CSConv
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME:S/src-//}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=         "It is supported on FreeBSD 5.3 and later"
.endif

.if ${ARCH} != "i386"
IGNORE=	"${ARCH} is not support."
.endif

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -liconv ${PTHREAD_LIBS}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
UPDATE_ARGS+=	ACLOCAL=${ACLOCAL} AUTOMAKE=${AUTOMAKE} \
		AUTOHEADER=${AUTOHEADER} AUTOCONF=${AUTOCONF} \
		LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE} \
		ACLOCAL_DIR="-I ${LOCALBASE}/share/aclocal -I ${ACLOCAL_DIR}"

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/../../acfiles/im_common.m4 \
		${WRKSRC}/configure.ac \
		${WRKSRC}/csconv.h \
		${WRKSRC}/converterPI/configure.in \
		${WRKSRC}/converterPI/test/icutest4linux.c \
		${WRKSRC}/converterPI/icuconv_relay.c \
		${WRKSRC}/converterPI/icuconv/common/config.h
	${REINPLACE_CMD} -e "s,ELIBBAD,ENOEXEC," \
		${WRKSRC}/converterPI/icuconv/common/icuconv.c
	for MKFLIN in `find ${WRKSRC} -name "Makefile.in"`; do \
		${REINPLACE_CMD} -e "/(CC)/s,-lc,,g" $${MKFLIN}; \
		${REINPLACE_CMD} -e "/(CC)/s,-ldl,,g" $${MKFLIN}; \
		${REINPLACE_CMD} -e '/(CC)/s,(LIBS),(LDFLAGS),g' $${MKFLIN}; \
		${REINPLACE_CMD} -e '/(CC)/s,{LIBS},{LDFLAGS},g' $${MKFLIN}; \
		${REINPLACE_CMD} -e "s,LIBS = @LIBS@,LDFLAGS = @LDFLAGS@,g" $${MKFLIN}; \
	done

pre-configure:
	@cd ${WRKSRC}/../../ && ${GMAKE} ${UPDATE_ARGS} update-acfiles
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} \
	 -I ../../acfiles -I ${LOCALBASE}/share/aclocal -I ${ACLOCAL_DIR}
	@cd ${WRKSRC}/converterPI/ && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOCONF}

post-configure:
	${REINPLACE_CMD} \
		-e "s,prefix = ${PREFIX},prefix = ${PREFIX}/lib/im," \
		`${FIND} ${WRKSRC} -type f -name Makefile`

.include <bsd.port.post.mk>
