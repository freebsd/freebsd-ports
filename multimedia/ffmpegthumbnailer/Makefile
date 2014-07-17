# Created by: Dierk Sacher <dierk@blaxxtarz.de>
# $FreeBSD$

PORTNAME=	ffmpegthumbnailer
PORTVERSION=	2.0.8
PORTREVISION=	3
CATEGORIES=	multimedia graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	clutton@zoho.com
COMMENT=	Lightweight video thumbnailer that can be used by file managers

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libswscale.so:${PORTSDIR}/multimedia/ffmpeg \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig --enable-gio

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GNOME MATE
OPTIONS_SUB=	yes

MATE_CONFIGURE_ENABLE=	thumbnailer

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
