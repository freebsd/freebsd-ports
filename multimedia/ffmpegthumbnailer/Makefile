# Created by: Dierk Sacher <dierk@blaxxtarz.de>
# $FreeBSD$

PORTNAME=	ffmpegthumbnailer
PORTVERSION=	2.0.8
PORTREVISION=	2
CATEGORIES=	multimedia graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	clutton@zoho.com
COMMENT=	Lightweight video thumbnailer that can be used by file managers

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libswscale.so:${PORTSDIR}/multimedia/ffmpeg \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-pthread -L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig --enable-gio

GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GNOME

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME+=	gconf2
GCONF_SCHEMAS=	ffmpegthumbnailer.schemas
.endif

post-install:
.if ${PORT_OPTIONS:MGNOME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/gconf/schemas
	${INSTALL_DATA} ${FILESDIR}/${GCONF_SCHEMAS} ${STAGEDIR}${PREFIX}/etc/gconf/schemas
.endif

.include <bsd.port.mk>
