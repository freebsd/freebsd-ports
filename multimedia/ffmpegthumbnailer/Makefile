# Created by: Dierk Sacher <dierk@blaxxtarz.de>
# $FreeBSD$

PORTNAME=	ffmpegthumbnailer
PORTVERSION=	2.0.8
PORTREVISION=	2
CATEGORIES=	multimedia graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	mbsd@isgroup.com.ua
COMMENT=	Lightweight video thumbnailer that can be used by file managers

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		swscale:${PORTSDIR}/multimedia/ffmpeg \
		jpeg:${PORTSDIR}/graphics/jpeg

CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig --enable-gio

GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GNOME

MAN1=		ffmpegthumbnailer.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOME}
PKGNAMESUFFIX+=	-gnome
USE_GNOME+=	gconf2
GCONF_SCHEMAS=	ffmpegthumbnailer.schemas
.endif

post-install:
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE} install-pkgconfigDATA
.if ${PORT_OPTIONS:MGNOME}
	${MKDIR} ${PREFIX}/etc/gconf/schemas
	${INSTALL_DATA} ${FILESDIR}/${GCONF_SCHEMAS} ${PREFIX}/etc/gconf/schemas
	@${SETENV} GCONF_CONFIG_SOURCE=xml:${GCONF_CONFIG_OPTIONS}:${PREFIX}/${GCONF_CONFIG_DIRECTORY} \
		gconftool-2 --makefile-install-rule ${PREFIX}/etc/gconf/schemas/${GCONF_SCHEMAS} \
		> /dev/null || ${TRUE}
.endif

.include <bsd.port.mk>
