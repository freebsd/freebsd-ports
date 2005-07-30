# New ports collection makefile for:    scim
# Date created:		20 May 2004
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	scim
PORTVERSION=	1.4.0
PORTREVISION=	0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=scim

MAINTAINER=	gaoj@cpsc.ucalgary.ca
COMMENT=	Smart Common Input Method platform

USE_GNOME=	gnomehack gnomehier gtk20 intlhack

USE_X_PREFIX=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/stlport" \
		LDFLAGS="-L${LOCALBASE}/lib -lstlport_gcc -lintl ${PTHREAD_LIBS}"
EXTRA_PATCHES=	${FILESDIR}/extra-patch-4-stable
.else
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
PLIST_SUB=	NOSTABLE=""
.endif

post-patch:
	${REINPLACE_CMD} 's|$$(datadir)/pixmaps|$$(prefix)/share/gnome/pixmaps|' \
			${WRKSRC}/data/pixmaps/Makefile.in
	${REINPLACE_CMD} -e 's|$$(datadir)/app|$$(prefix)/share/gnome/app| ; \
		 s|$$(datadir)/control|$$(prefix)/share/gnome/control| ; \
		 /^scim_setup_LDFLAGS/s|=|= ${PTHREAD_LIBS}|' \
			${WRKSRC}/extras/setup/Makefile.in

post-install:
	@gtk-query-immodules-2.0 > ${PREFIX}/etc/gtk-2.0/gtk.immodules
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type pkg_info -D ${PKGNAME}

.include <bsd.port.post.mk>
