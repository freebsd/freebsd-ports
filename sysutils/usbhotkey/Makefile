# Created by: Nikos Ntarmos <ntarmos@ceid.upatras.gr>
# $FreeBSD$

PORTNAME=	usbhotkey
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	ntarmos@ceid.upatras.gr
COMMENT=	Utility to remap USB keyboards under X11

LICENSE=	GPLv2

LIB_DEPENDS=	libhid.so:${PORTSDIR}/devel/libhid \
		libXtst.so:${PORTSDIR}/x11/libXtst

USES=		gmake
USE_RUBY=	yes
HAS_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/ruby-${RUBY_VER} \
		-I${LOCALBASE}/include/ruby-${RUBY_VER}/${RUBY_ARCH}
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	GUI
OPTIONS_DEFAULT=	GUI
GUI_DESC=	Enable GUI bits (via Imlib)

GUI_LIB_DEPENDS=	libImlib.so:${PORTSDIR}/graphics/imlib
GUI_CONFIGURE_OFF=	--without-Imlib

.include <bsd.port.mk>
