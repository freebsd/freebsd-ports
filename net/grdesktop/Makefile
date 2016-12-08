# Created by: Florent Thoumie <flz@xbsd.org>
# $FreeBSD$

PORTNAME=	grdesktop
PORTVERSION=	0.23
PORTREVISION=	13
CATEGORIES=	net
MASTER_SITES=	SAVANNAH

MAINTAINER=	flz@FreeBSD.org
COMMENT=	GNOME frontend for the remote desktop client (rdesktop)

RUN_DEPENDS=	rdesktop:net/rdesktop

GNU_CONFIGURE=	yes
USES=		gettext-tools gmake pathfix pkgconfig
USE_GNOME=	libgnomeui gnomeprefix
GCONF_SCHEMAS=	grdesktop.schemas
INSTALLS_OMF=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-keymap-path=${LOCALBASE}/share/rdesktop/keymaps

post-patch:
	@${REINPLACE_CMD} -e 's|^\(GETTEXT_PACKAGE =\).*|\1 grdesktop|' ${WRKSRC}/po/Makefile.in.in

post-install:
	@${INSTALL_DATA} ${STAGEDIR}${PREFIX}/share/pixmaps/grdesktop/icon.png ${STAGEDIR}${PREFIX}/share/pixmaps/grdesktop.png

.include <bsd.port.mk>
