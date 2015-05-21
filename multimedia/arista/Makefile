# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	arista
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://programmer-art.org/media/releases/arista-transcoder/ \
		http://launchpadlibrarian.net/28489828/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Easy to use multimedia transcoder for the GNOME Desktop

BROKEN=		Uses unknown GNOME component pygnomedesktop
DEPRECATED=	Broken since update to gnome3
EXPIRATION_DATE=	2015-06-02

USES=		desktop-file-utils gettext python
USE_GSTREAMER=	faac x264 lame mpeg2enc
USE_GNOME=	pygnomedesktop
USE_PYTHON=	distutils

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|Icon=.*|Icon=arista.svg|g' \
		${WRKSRC}/arista.desktop

post-install:
	@${INSTALL_DATA} ${WRKSRC}/ui/icon.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps/arista.svg

.include <bsd.port.mk>
