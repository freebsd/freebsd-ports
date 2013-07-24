# Created by: ntarmos@ceid.upatras.gr
# $FreeBSD$

PORTNAME=		usbhotkey
PORTVERSION=		0.4
CATEGORIES=		sysutils
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/

MAINTAINER=		ntarmos@ceid.upatras.gr
COMMENT=		A utility to remap USB keyboards under X11

LIB_DEPENDS=		hid.0:${PORTSDIR}/devel/libhid \
			Xtst.6:${PORTSDIR}/x11/libXtst

BROKEN=	Does not patch

OPTIONS_DEFINE=	GUI
OPTIONS_DEFAULT=	GUI
GUI_DESC=	Enable GUI bits (Imlib dependency)

USE_RUBY=		yes
USE_GMAKE=		yes
HAS_CONFIGURE=		yes

.include <bsd.port.options.mk>

CPPFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/ruby-${RUBY_VER} \
		-I${LOCALBASE}/include/ruby-${RUBY_VER}/${RUBY_ARCH}
LDFLAGS+=	-L${LOCALBASE}/lib

.if ${PORT_OPTIONS:MGUI}
LIB_DEPENDS+=		Imlib.5:${PORTSDIR}/graphics/imlib
.else
CONFIGURE_ARGS+=	--without-Imlib
.endif

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
EXTRA_PATCHES+=		${PATCHDIR}/extra-patch-main.c
.endif

.include <bsd.port.post.mk>
