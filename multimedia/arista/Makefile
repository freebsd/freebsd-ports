# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	arista
PORTVERSION=	0.9.6
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://programmer-art.org/media/releases/arista-transcoder/ \
		http://launchpadlibrarian.net/28489828/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	An easy to use multimedia transcoder for the GNOME Desktop

USES=		gettext
USE_GSTREAMER=	faac x264 lame mpeg2enc
USE_GNOME=	pygnomedesktop
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|Icon=.*|Icon=arista.svg|g' \
		${WRKSRC}/arista.desktop

post-install:
	@${INSTALL_DATA} ${WRKSRC}/ui/icon.svg \
		${PREFIX}/share/pixmaps/arista.svg
	@-update-desktop-database

.include <bsd.port.mk>
