# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	subtitleeditor
PORTVERSION=	0.41.1
CATEGORIES=	multimedia
MASTER_SITES=	http://download.gna.org/${PORTNAME}/${PORTVERSION:C/\.[0-9]*$//}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Subtitle editor

LICENSE=	GPLv3

BUILD_DEPENDS=	iso-codes>0:misc/iso-codes
LIB_DEPENDS=	libglademm-2.4.so:devel/libglademm24 \
		libpcre.so:devel/pcre \
		libenchant.so:textproc/enchant
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		desktop-file-utils gettext gmake libtool pkgconfig
USE_GNOME=	gtkmm24 intltool
USE_GSTREAMER=	good mm
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS OPENGL
OPTIONS_SUB=	yes

NLS_CONFIGURE_OFF=	--disable-nls

OPENGL_LIB_DEPENDS=	libgtkglextmm-x11-1.2.so:x11-toolkits/gtkglextmm
OPENGL_USE=		gl=glu
OPENGL_CONFIGURE_ENABLE=gl

.include <bsd.port.mk>
