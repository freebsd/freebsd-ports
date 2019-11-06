# Created by: Grigori Goronzy <greg@chown.ath.cx>
# $FreeBSD$

PORTNAME=	gxine
PORTVERSION=	0.5.910
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF/xine/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alternative GUI for the Xine media player

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnspr4.so:devel/nspr \
		libmozjs185.so:lang/spidermonkey185 \
		libxine.so:multimedia/libxine

USES=		desktop-file-utils gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	gtk30
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-hal --with-libintl-prefix=${LOCALBASE} \
		--with-gtk3 --without-dbus --disable-integration-wizard 
INSTALLS_ICONS=	yes
LLD_UNSAFE=	yes

OPTIONS_DEFINE=	LIRC NLS WEBPLUGIN
OPTIONS_SUB=	yes

WEBPLUGIN_DESC=	Build and/or install Web browser plugins

LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CONFIGURE_ENABLE=	lirc
LIRC_USES=		localbase

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

WEBPLUGIN_USE=			xorg=xaw
WEBPLUGIN_USES=			webplugin:native xorg
WEBPLUGIN_CONFIGURE_WITH=	browser-plugin
WEBPLUGIN_DIR=			${PREFIX}/lib/gxine
WEBPLUGIN_FILES=		gxineplugin.so

post-patch:
	@${REINPLACE_CMD} -e \
		'/CFLAGS/s|-I/usr/local/include|| ; \
		 /CFLAGS/s|-L/usr/local/lib|| ; \
		 /CPPFLAGS/s|-I/usr/local/include|| ; \
		 s|XINE_LIST=.*|XINE_LIST=|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|@MAKE_PNG_TRUE@|#|' ${WRKSRC}/pixmaps/Makefile.in

post-install-WEBPLUGIN-on:
	@${STRIP_CMD} ${STAGEDIR}${WEBPLUGIN_DIR}/${WEBPLUGIN_FILES}

.include <bsd.port.mk>
