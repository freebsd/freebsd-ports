# New ports collection makefile for:	iiimf-client-lib
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	client-lib
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}-src-${IIIMF_VER}.tgz

MAINTAINER=	kcwu@csie.org
COMMENT=	Internet/Intranet Input Method Client Framework

LIB_DEPENDS=	iiimp.0:${PORTSDIR}/textproc/iiimf-protocol-lib

IIIMF_VER=	r12_0_1-svn1891
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}
INSTALL_WRKSRC=	${WRKSRC}/lib/iiimcf
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_ICONV=	yes
USE_REINPLACE=	yes
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_AUTOMAKE_VER=	19
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -liconv" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/iiimf
DIRS=		lib/EIMIL lib/iiimcf

post-patch:
.for DIR in ${DIRS}
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/${DIR}/configure.ac
.endfor
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/acfiles/im_common.m4

pre-configure:
.for DIR in ${DIRS}
	cd ${WRKSRC}/${DIR} && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal -I ../../acfiles
	${TOUCH} ${WRKSRC}/${DIR}/config.h.in
.endfor

# XXX following are dup what bsd.*.mk do. how to deal this neatly?
run-autotools:
.for DIR in ${DIRS}
	@(cd ${WRKSRC}/${DIR} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} \
		${AUTOMAKE_ARGS})
	@(cd ${WRKSRC}/${DIR} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOCONF} \
		${AUTOCONF_ARGS})
	@(cd ${WRKSRC}/${DIR} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOHEADER} \
		${AUTOHEADER_ARGS})
.endfor

patch-autotools:
.for DIR in ${DIRS}
	cd ${WRKSRC}/${DIR} && ${REINPLACE_CMD} -e "s^\$$ac_aux_dir/ltconfig^${LTCONFIG}^g" \
		-e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LTMAIN}^g" \
		-e '/^LIBTOOL=/s^\$$(top_builddir)/libtool^${LIBTOOL}^g' \
		${LIBTOOLFILES}
.endfor

do-configure:
.for DIR in ${DIRS}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${CONFIGURE_ENV} ${SH} configure ${CONFIGURE_ARGS}
.endfor

do-build:
.for DIR in ${DIRS}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
.endfor

.include <bsd.port.mk>
