# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net/vinagre/Makefile,v 1.48 2012/09/01 23:02:11 mezz Exp $

PORTNAME=	vinagre
PORTVERSION=	2.30.3
PORTREVISION=	6
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC client for the GNOME Desktop

LIB_DEPENDS=	libgtk-vnc-1.0.so:${PORTSDIR}/net/gtk-vnc \
		libavahi-core.so:${PORTSDIR}/net/avahi-app \
		libavahi-ui.so:${PORTSDIR}/net/avahi-gtk \
		libgdbm.so:${PORTSDIR}/databases/gdbm \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring

CONFLICTS=	vinagre-3.[0-9]*

USES=		desktop-file-utils pathfix gettext gmake libtool pkgconfig \
		shared-mime-info tar:bzip2
USE_GNOME=	gnomeprefix intlhack vte gconf2 gnomedocutils gnomepanel
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-avahi --enable-applet -enable-ssh
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	vinagre.schemas

OPTIONS_DEFINE=	TELEPATHY DOCS
OPTIONS_DEFAULT=TELEPATHY
OPTIONS_SUB=	yes
TELEPATHY_DESC=	Telepathy integration
TELEPATHY_LIB_DEPENDS=	libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib
TELEPATHY_CONFIGURE_ENABLE=	telepathy

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} '/^libvinagre_la_LIBADD =/s/$$/ -lgmodule-2.0/' \
		${WRKSRC}/vinagre/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog MAINTAINERS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
