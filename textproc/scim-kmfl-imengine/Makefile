# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	scim-kmfl-imengine
PORTVERSION=	0.9.9
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	SF/kmfl/kmfl/${PORTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	SCIM KMFL IMEngine platform for Keyman (KMN) language keyboards

BUILD_DEPENDS=	scim:textproc/scim
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libkmfl.so:textproc/libkmfl \
		libkmflcomp.so:textproc/kmflcomp \
		libpng.so:graphics/png
RUN_DEPENDS=	kmflcomp:textproc/kmflcomp \
		scim:textproc/scim

USE_XORG=	x11 xkbfile xproto
USE_GNOME=	glib20 gtk20 intlhack
USES=		gettext iconv pkgconfig libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS
DOCSDIR=	${PREFIX}/share/doc/kmfl/${PORTNAME}
PORTDOCS=	AUTHORS COPYING ChangeLog
SUB_FILES=	pkg-message

.if exists(${LOCALBASE}/bin/skim)
pre-patch:
	@${ECHO_MSG} ---------------------------------------------------------
	@${ECHO_MSG}   You have SKIM installed. KMFL-SCIM-IMEngine will work
	@${ECHO_MSG}   and you will be able to use textproc/kmfl-* key-
	@${ECHO_MSG}   boards, but KMFL IME does not have SKIM frontend yet.
	@${ECHO_MSG}   Please refer to the textproc/kmflcomp docs on how to
	@${ECHO_MSG}   use KMFL keyboards in QT applications.
	@${ECHO_MSG} ---------------------------------------------------------
.endif

post-patch:
	@${REINPLACE_CMD} \
		's|/usr/X11R6/lib|${LOCALBASE}/lib|' \
		${WRKSRC}/src/Makefile.* ${WRKSRC}/src/xkbmap.cpp
	@${REINPLACE_CMD} \
		's|/usr/lib|${LOCALBASE}/lib|' \
		${WRKSRC}/scim_kmfl_imengine_setup/scim_kmfl_imengine_setup.cpp
	@${REINPLACE_CMD} \
		's|$$(datadir)/scim/kmfl|$$(datadir)/kmfl|g' \
		${WRKSRC}/src/Makefile.* \
		${WRKSRC}/scim_kmfl_imengine_setup/Makefile.*
	@${REINPLACE_CMD} \
		's|SCIM_DATADIR="$$datadir/scim"|SCIM_DATADIR="$$datadir"|' \
		${WRKSRC}/configure.in
	@${REINPLACE_CMD} \
		's|"\.scim" SCIM_PATH_DELIM_STRING "kmfl"|".kmfl"|' \
		${WRKSRC}/scim_kmfl_imengine_setup/scim_kmfl_imengine_setup.cpp
	@${REINPLACE_CMD} \
		's|"\.scim" + SCIM_PATH_DELIM_STRING + "kmfl"|".kmfl"|' \
		${WRKSRC}/src/scim_kmfl_imengine.cpp

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
. endfor

.include <bsd.port.mk>
