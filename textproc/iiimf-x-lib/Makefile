# New ports collection makefile for:	iiimf-x-lib
# Date created:		8 Sep 2004
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	x-lib
PORTVERSION=	12.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	Internet/Intranet Input Method X Client Framework

LIB_DEPENDS=	iiimp.1:${PORTSDIR}/textproc/iiimf-protocol-lib \
		iiimcf.3:${PORTSDIR}/textproc/iiimf-client-lib
RUN_DEPENDS=	${LOCALBASE}/lib/iiim/csconv/csconv.so:${PORTSDIR}/textproc/iiimf-csconv

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_MOTIF=	yes
USE_OPENSSL=	yes
USE_AUTOTOOLS=	automake:19:env autoconf:259:env libtool:15:env
WANT_AUTOHEADER_VER=	259

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
BUILDDIR=	${WRKSRC}/iiimxcf/xiiimp.so

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=	is supported on FreeBSD 5.3 and later only
.endif

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -lintl ${PTHREAD_LIBS}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/Makefile ${BUILDDIR}/Makefile.am
	${REINPLACE_CMD} -e "s,/usr/lib/iiim,${LOCALBASE}/lib/iiim,g" \
		${WRKSRC}/lib/CSConv/csconv.h

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${GMAKE} reconfig
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GMAKE} config

.include <bsd.port.post.mk>
