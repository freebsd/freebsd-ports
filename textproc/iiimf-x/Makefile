# New ports collection makefile for:	iiimf-x
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	x
PORTVERSION=	12.2
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Internet/Intranet Input Method X Client Framework

LIB_DEPENDS=	iiimp.1:${PORTSDIR}/textproc/iiimf-protocol-lib \
		iiimcf.3:${PORTSDIR}/textproc/iiimf-client-lib
RUN_DEPENDS=	${LOCALBASE}/lib/iiim/xiiimp.so:${PORTSDIR}/textproc/iiimf-x-lib

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11 ice xt
USE_AUTOTOOLS=	automake:19:env autoconf:262:env libtool:22:env

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
BUILDDIR=	${WRKSRC}/iiimxcf/htt_xbe

.include <bsd.port.pre.mk>

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
