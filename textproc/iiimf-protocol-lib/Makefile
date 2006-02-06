# New ports collection makefile for:	iiimf-protocol-lib
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	protocol-lib
PORTVERSION=	12.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	Internet/Intranet Input Method Framework protocol library

ONLY_FOR_ARCHS=	i386

INSTALLS_SHLIB=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:19:env autoconf:259:env libtool:15:env
WANT_AUTOHEADER_VER=	259

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
BUILDDIR=	${WRKSRC}/lib/iiimp

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=	is supported on FreeBSD 5.3 and later only
.endif

CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	${REINPLACE_CMD} \
		-e '/^pkgconfigdir/s,$$(libdir),%%PREFIX%%/libdata,g' \
		${BUILDDIR}/Makefile.am
	${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/Makefile ${BUILDDIR}/Makefile.am

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${GMAKE} reconfig
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GMAKE} config

.include <bsd.port.post.mk>
