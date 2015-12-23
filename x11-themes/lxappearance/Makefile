# Created by: chinsan
# $FreeBSD$

PORTNAME=	lxappearance
PORTVERSION=	0.6.1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	SF/lxde/LXAppearance

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Desktop-independent theme switcher for GTK+

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USES=		gettext-tools gmake pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool
CONFIGURE_ARGS=	--enable-dbus
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
