# New ports collection makefile for:	stuphead
# Date created:		07 December 2000
# Whom:			Sergey Osokin aka oZZ <ports@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stuphead
PORTVERSION=	0.5.3
PORTREVISION=	4
CATEGORIES=	mail gnome
MASTER_SITES=	# http://stuphead.asplinux.ru/stuphead/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}-${PORTVERSION}-1.patch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lightweight MUA for X11

EXPIRATION_DATE=2005-08-01
DEPRECATED=	Mastersite disappeared

USE_ICONV=	yes
USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--enable-threads \
		--prefix=${PREFIX}

.if defined (WITH_PIXBUF)
LIB_DEPENDS+=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
.else
CONFIGURE_ARGS+=	--disable-gdk-pixbuf \
			--disable-gdk_pixbuftest
.endif

.if defined (WITH_GNOME)
PLIST_SUB+=	GNOME=""
CONFIGURE_ARGS+=	--enable-gnome
.else
PLIST_SUB+=	GNOME="@comment "
CONFIGURE_ARGS+=	--disable-imlib \
			--disable-imlibtest
.endif

.if defined (WITH_MOZILLA)
PLIST_SUB+=	MOZILLA=""
CONFIGURE_ARGS+=	--enable-mozilla
RUN_DEPENDS+=	${PREFIX}/bin/mozilla:${PORTSDIR}/www/mozilla
.else
PLIST_SUB+=	MOZILLA="@comment "
.endif

.if defined (WITH_ISPELL)
RUN_DEPENDS+=	${LOCALBASE}/bin/ispell-ru:${PORTSDIR}/russian/rus-ispell
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's#DATADIRNAME=lib#DATADIRNAME=share#g ; \
		s#/usr/bin/gnome-config#$(PREFIX)/bin/gnome-config#g ; \
		s|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

do-install:
.if defined (WITH_MOZILLA)
	@ ${INSTALL_SCRIPT} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME}bin ${PREFIX}/bin
.else
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME}bin ${PREFIX}/bin/${PORTNAME}
.endif
	@ ${MKDIR} ${PREFIX}/share/pixmaps
	@ ${INSTALL_DATA} ${WRKSRC}/src/pixmaps/${PORTNAME}.xpm ${PREFIX}/share/pixmaps/${PORTNAME}.xpm
	@ ${INSTALL_DATA} ${WRKSRC}/po/fr.gmo ${PREFIX}/share/locale/fr/LC_MESSAGES/${PORTNAME}.mo
	@ ${INSTALL_DATA} ${WRKSRC}/po/ru.gmo ${PREFIX}/share/locale/ru/LC_MESSAGES/${PORTNAME}.mo
.if defined (WITH_GNOME)
	@ ${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/gnome/apps/Internet
.endif

.include <bsd.port.mk>
