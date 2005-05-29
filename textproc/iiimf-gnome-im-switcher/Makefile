# New ports collection makefile for:	iiimf-gnome-im-switcher
# Date created:		10 Sep 2004
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-im-switcher
PORTVERSION=	12.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	IIIMF gnome input method switcher

ONLY_FOR_ARCHS=	i386

USE_X_PREFIX=	yes

USE_BZIP2=	yes
USE_REINPLACE=  yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	intltool gconf2 libglade2 libgnomeui \
		gnomepanel gnomeprefix gnomehack
WANT_AUTOCONF_VER=	259
WANT_AUTOHEADER_VER=	259
WANT_AUTOMAKE_VER=	19
WANT_LIBTOOL_VER=	15

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
BUILDDIR=	${WRKSRC}/gnome-im-switcher

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=	It is supported on FreeBSD 5.3 and later.
.endif

CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lintl ${PTHREAD_LIBS}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	${REINPLACE_CMD} \
		-e '/^serverdir/s,$$[(]libdir[)],%%LOCALBASE%%/libdata,g' \
		-e '/^uidir/s,$$[(]datadir[)]/,&gnome/,g' \
		${BUILDDIR}/src/Makefile.am
	${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/Makefile ${BUILDDIR}/Makefile.am \
		${BUILDDIR}/src/Makefile.am
	${REINPLACE_CMD} -e "/GNOMECC_DATA_DIR/s,/share/,&gnome/,g" \
		${BUILDDIR}/configure.ac
	${REINPLACE_CMD} -e "/^GNOMECC_.*_DIR=/s,[(]datadir[)]/,&gnome/,g" \
		${BUILDDIR}/configure.ac

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${GMAKE} bootstrap
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GMAKE} config

post-configure:
	${REINPLACE_CMD} -e '/^pkgdatadir/s,[(]datadir[)]/,&gnome/,g' \
		-e '/^iconsdir/s,[(]datadir[)]/,&gnome/,g' \
		${BUILDDIR}/src/Makefile

.include <bsd.port.post.mk>
