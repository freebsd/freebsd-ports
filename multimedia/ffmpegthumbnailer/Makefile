# New ports collection makefile for:	ffmpegthumbnailer
# Date created:		Mo 18 Feb 2008 06:11:13 CET
# Whom:			Dierk Sacher <dierk@blaxxtarz.de>
#
# $FreeBSD$

PORTNAME=	ffmpegthumbnailer
PORTVERSION=	2.0.8
PORTREVISION=	1
CATEGORIES=	multimedia graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	mbsd@isgroup.com.ua
COMMENT=	Lightweight video thumbnailer that can be used by file managers

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		swscale:${PORTSDIR}/multimedia/ffmpeg \
		jpeg.11:${PORTSDIR}/graphics/jpeg

CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig --enable-gio

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig _glib20
USE_LDCONFIG=	yes

WANT_GNOME=	yes

OPTIONS_DEFINE=	GNOME

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGNOME}
PKGNAMESUFFIX+=	-gnome
GCONF_SCHEMAS=	ffmpegthumbnailer.schemas
.endif

MAN1=		ffmpegthumbnailer.1

post-install:
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE} install-pkgconfigDATA
.if ${PORT_OPTIONS:MGNOME}
	${INSTALL_DATA} ${FILESDIR}/${GCONF_SCHEMAS} ${LOCALBASE}/etc/gconf/schemas
	@${SETENV} GCONF_CONFIG_SOURCE=`gconftool-2 --get-default-source` \
		gconftool-2 --makefile-install-rule ${LOCALBASE}/etc/gconf/schemas/${GCONF_SCHEMAS} \
		> /dev/null
.endif
.include <bsd.port.post.mk>
