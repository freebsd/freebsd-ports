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

USES=		gmake pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
CONFIGURE_ARGS=	--enable-dbus
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
