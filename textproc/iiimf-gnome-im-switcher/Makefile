# New ports collection makefile for:	iiimf-gnome-im-switcher
# Date created:		10 Sep 2004
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-im-switcher
PORTVERSION=	12.2
PORTREVISION=	10
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IIIMF gnome input method switcher

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	intltool gconf2 libglade2 libgnomeui \
		gnomepanel gnomeprefix gnomehack
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	automake:19:env autoconf:262:env libtool:22:env

GCONF_SCHEMAS=	gnome-im-properties.schemas gnome-im-switcher.schemas

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
BUILDDIR=	${WRKSRC}/gnome-im-switcher

.include <bsd.port.pre.mk>

CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lintl ${PTHREAD_LIBS}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	${REINPLACE_CMD} \
		-e '/^serverdir/s,$$[(]libdir[)],%%LOCALBASE%%/libdata,g' \
		${BUILDDIR}/src/Makefile.am
	${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/Makefile ${BUILDDIR}/Makefile.am \
		${BUILDDIR}/src/Makefile.am

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${GMAKE} bootstrap
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GMAKE} config

.include <bsd.port.post.mk>
