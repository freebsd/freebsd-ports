# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/multimedia/libgnome-media-profiles/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	libgnome-media-profiles
PORTVERSION=	3.0.0
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library that contains code to manage media profiles

CONFLICTS=	gnome-media-2.[0-9]*

USE_GNOME=	gtk30 gconf2 intlhack gnomedocutils
GNU_CONFIGURE=	yes
USE_GSTREAMER=	yes
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
USES=		gettext gmake pathfix pkgconfig

GCONF_SCHEMAS=	gnome-media-profiles.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|gladeui-3.0|gladeui-5.0|g' ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*

.include <bsd.port.mk>
