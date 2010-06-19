# New ports collection makefile for:    scim-kmfl-imengine
# Date created:		10 October 2007
# Whom:			Nikola Lecic <nikola.lecic@anthesphoria.net>
#
# $FreeBSD$
#

PORTNAME=	scim-kmfl-imengine
PORTVERSION=	0.9.9
CATEGORIES=	textproc
MASTER_SITES=	SF/kmfl/kmfl/${PORTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	SCIM KMFL IMEngine platform for Keyman (KMN) language keyboards

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		freetype.9:${PORTSDIR}/print/freetype2 \
		kmfl.0:${PORTSDIR}/textproc/libkmfl \
		kmflcomp.0:${PORTSDIR}/textproc/kmflcomp \
		png.6:${PORTSDIR}/graphics/png
RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp \
		scim:${PORTSDIR}/textproc/scim

USE_XORG=	x11 xkbfile xproto
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	glib20 gtk20 intlhack
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCSDIR=	${PREFIX}/share/doc/kmfl/${PORTNAME}
PORTDOCS=	AUTHORS COPYING ChangeLog
SUB_FILES=	pkg-message

.if exists(${LOCALBASE}/bin/skim)
pre-patch:
	@${ECHO_MSG} ---------------------------------------------------------
	@${ECHO_MSG}   You have SKIM installed. KMFL-SCIM-IMEngine will work
	@${ECHO_MSG}   and you will be able to use textproc/scim-kmfl-* key-
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

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
