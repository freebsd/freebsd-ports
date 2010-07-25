# New ports collection makefile for:	vinagre
# Date created:				16 December 2007
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net/vinagre/Makefile,v 1.40 2010/05/04 14:13:29 kwm Exp $
#

PORTNAME=	vinagre
PORTVERSION=	2.30.1
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC client for the GNOME Desktop

LIB_DEPENDS=	gtk-vnc-1.0.0:${PORTSDIR}/net/gtk-vnc \
    		avahi-core.7:${PORTSDIR}/net/avahi-app \
		avahi-ui.0:${PORTSDIR}/net/avahi-gtk \
		gnome-keyring:${PORTSDIR}/security/gnome-keyring

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack vte gconf2 gnomedocutils \
		gnomepanel
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-avahi --enable-applet -enable-ssh
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	vinagre.schemas

MAN1=		vinagre.1

OPTIONS=	TELEPATHY "Enable telepathy integration" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_TELEPATHY)
CONFIGURE_ARGS+=--enable-telepathy
LIB_DEPENDS+=	telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib
PLIST_SUB+=	TELEPATHY=""
.else
CONFIGURE_ARGS+=--disable-telepathy
PLIST_SUB+=	TELEPATHY="@comment "
.endif

post-install:
	@-update-desktop-database > /dev/null
	@-update-mime-database ${PREFIX}/share/mime > /dev/null
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog MAINTAINERS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
