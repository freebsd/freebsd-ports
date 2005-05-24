# New ports collection makefile for:	iiimf-x
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	x
PORTVERSION=	12.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	Internet/Intranet Input Method X Client Framework

LIB_DEPENDS=	iiimp.1:${PORTSDIR}/textproc/iiimf-protocol-lib \
		iiimcf.3:${PORTSDIR}/textproc/iiimf-client-lib
RUN_DEPENDS=	${LOCALBASE}/lib/iiim/xiiimp.so:${PORTSDIR}/textproc/iiimf-x-lib

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_REINPLACE=  yes
USE_GMAKE=	yes
USE_XLIB=	yes
WANT_AUTOCONF_VER=	259
WANT_AUTOHEADER_VER=	259
WANT_AUTOMAKE_VER=	19
WANT_LIBTOOL_VER=	15

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
BUILDDIR=	${WRKSRC}/iiimxcf/htt_xbe

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=	It is supported on FreeBSD 5.3 and later.
.endif

CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
CXXFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/Makefile ${BUILDDIR}/Makefile.am \
		${BUILDDIR}/src/watchdog.c

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${GMAKE} reconfig
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GMAKE} config

.include <bsd.port.post.mk>
