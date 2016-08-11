# Created by: Zastupov Stepan [RedChrom] <redchrom@mail.ru>
# $FreeBSD$

PORTNAME=	audacious
PORTVERSION=	3.7.2
CATEGORIES=	multimedia audio
MASTER_SITES=	http://distfiles.audacious-media-player.org/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Media player based on BMP and XMMS

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib desktop-file-utils gettext-tools gmake \
	pkgconfig tar:bzip2
USE_XORG=	x11 sm
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALLS_ICONS=	yes

CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

OPTIONS_MULTI=	TOOLKITS
OPTIONS_MULTI_TOOLKITS=	GTK2 QT5
OPTIONS_EXCLUDE=	QT5
OPTIONS_DEFINE=	DBUS ICONV NLS EXECINFO
OPTIONS_DEFAULT=DBUS GTK2 ICONV EXECINFO
DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
ICONV_USES=	iconv
GTK2_USE=	gnome=gtk20
GTK2_IMPLIES=	DBUS
GTK2_CONFIGURE_ENABLE=	gtk
QT5_USE=	qt5=core,gui,widgets
QT5_CONFIGURE_ENABLE=	qt
QT5_IMPLIES=	DBUS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_OFF=	--disable-nls
NLS_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-Makefile
EXECINFO_USES=	execinfo
OPTIONS_SUB=	yes
EXECINFO_DESC=	Build with libexecinfo support

.include <bsd.port.options.mk>

post-patch:
.if  ${PORT_OPTIONS:MEXECINFO} || exists(${LOCALBASE}/lib/libexecinfo.so)
	@${REINPLACE_CMD} 's|-lm |-lm -L${LOCALBASE}/lib -lexecinfo |' \
		${WRKSRC}/src/audacious/Makefile
	@${REINPLACE_CMD} 's|-laudcore|-laudcore -L${LOCALBASE}/lib -lexecinfo|' \
		${WRKSRC}/audacious.pc.in
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/aud*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*

.include <bsd.port.mk>
