# New ports collection makefile for:	iiimf-client-lib
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	client-lib
PORTVERSION=	12.2
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Internet/Intranet Input Method Client Framework

LIB_DEPENDS=	iiimp.1:${PORTSDIR}/textproc/iiimf-protocol-lib
RUN_DEPENDS=	${LOCALBASE}/lib/iiim/csconv/csconv.so:${PORTSDIR}/textproc/iiimf-csconv

ONLY_FOR_ARCHS=	i386

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:19:env autoconf:262:env libtool:22:env

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
BUILDDIR=	${WRKSRC}/lib/iiimcf

.include <bsd.port.pre.mk>

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	${REINPLACE_CMD} \
		-e '/^pkgconfigdir/s,$$(libdir),%%PREFIX%%/libdata,g' \
		${BUILDDIR}/Makefile.am
	${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/Makefile \
		${BUILDDIR}/Makefile.am \
		${BUILDDIR}/../EIMIL/Makefile.am
	${REINPLACE_CMD} -e "s,/usr/lib/iiim,${LOCALBASE}/lib/iiim,g" \
		${WRKSRC}/lib/CSConv/csconv.h

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${GMAKE} reconfig
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GMAKE} config

.include <bsd.port.post.mk>
