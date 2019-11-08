# Created by: Rozhuk Ivan rozhuk.im@gmail.com
# $FreeBSD$

PORTNAME=		aravis
DISTVERSIONPREFIX=	ARAVIS_
DISTVERSION=		0_5_12
CATEGORIES=		multimedia

MAINTAINER=		rozhuk.im@gmail.com
COMMENT=		Camera control and image acquisition viewer

LICENSE=		LGPL21+
LICENSE_FILE=		${WRKSRC}/COPYING

CONFLICTS_INSTALL=	${PORTNAME}*

LIB_DEPENDS+=		libaravis-0.6.so:devel/libaravis \
			libnotify.so:devel/libnotify

USES=			autoreconf gettext gmake gnome libtool pkgconfig
USE_GNOME=		cairo glib20 intltool gtk30
USE_GSTREAMER1=		yes
GNU_CONFIGURE=		yes
# USE_LDCONFIG=		yes
INSTALLS_ICONS=		yes

USE_GITHUB=		yes
GH_ACCOUNT=		AravisProject
GH_PROJECT=		aravis

CONFIGURE_ARGS=		--enable-packet-socket=no --enable-viewer=yes	\
			--enable-gst-plugin=no --enable-gst-0.10-plugin=no \
			--enable-gtk-doc=no --enable-cpp-test=no \
			--enable-usb=no --enable-zlib-pc=yes
MAKE_ARGS=		pkgconfigdir="${PREFIX}/libdata/pkgconfig"

pre-configure:
	${ECHO_CMD} "EXTRA_DIST =" >> ${WRKSRC}/gtk-doc.make
	@${REINPLACE_CMD} -e 's|GTK_DOC_CHECK(\[1.14\],\[--flavour no-tmpl\])||' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|^arv_viewer_LDADD.*=.*|arv_viewer_LDADD = $${ARAVIS_VIEWER_LIBS} -laravis-0.6|' \
		${WRKSRC}/viewer/Makefile.am

.include <bsd.port.mk>
