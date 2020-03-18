# Created by: Nikos Ntarmos <ntarmos@ceid.upatras.gr>
# $FreeBSD$

PORTNAME=	usbhotkey
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to remap USB keyboards under X11

LICENSE=	GPLv2

BROKEN_FreeBSD_11_powerpc64=	fails to compile on powerpc64 elfv1: ruby.h: wrong number of arguments specified for 'deprecated' attribute
BROKEN_FreeBSD_12_powerpc64=	fails to compile on powerpc64 elfv1: ruby.h: wrong number of arguments specified for 'deprecated' attribute

LIB_DEPENDS=	libhid.so:devel/libhid \
		libXtst.so:x11/libXtst

USES=		gmake
USE_RUBY=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/ruby-${RUBY_VER} \
		-I${LOCALBASE}/include/ruby-${RUBY_VER}/${RUBY_ARCH}
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-lX11

CONFIGURE_ARGS=	--without-Imlib

.include <bsd.port.mk>
