# New ports collection makefile for:	iiimf-le-unit
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	le-unit
PORTVERSION=	12.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	IIIMF UNIcode Table based generic composition engine

LIB_DEPENDS=	iiimp.1:${PORTSDIR}/textproc/iiimf-protocol-lib \
		iiimcf.3:${PORTSDIR}/textproc/iiimf-client-lib
RUN_DEPENDS=	iiimd:${PORTSDIR}/textproc/iiimf-server

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_ICONV=	yes
USE_REINPLACE=  yes
USE_GMAKE=	yes
USE_XLIB=	yes
WANT_AUTOCONF_VER=	259
WANT_AUTOHEADER_VER=	259
WANT_AUTOMAKE_VER=	19
WANT_LIBTOOL_VER=	15

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
BUILDDIR=	${WRKSRC}/leif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=	It is supported on FreeBSD 5.3 and later.
.endif

CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib -liconv ${PTHREAD_LIBS}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/Makefile ${BUILDDIR}/Makefile.am \
		${BUILDDIR}/../lib/EIMIL/Makefile.am

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${GMAKE} reconfig
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GMAKE} config

pre-install:
	${REINPLACE_CMD} \
		-e "/^BUILDDIRS/s,lib/EIMIL,,g" \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>
