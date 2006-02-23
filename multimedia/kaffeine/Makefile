# New ports collection makefile for:	kaffeine
# Date created:				2003-06-25
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kaffeine
PORTVERSION=	0.7.1
PORTREVISION=	4
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kaffeine

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A xine-base multimedia player

LIB_DEPENDS=	xine.15:${PORTSDIR}/multimedia/libxine

USE_BZIP2=		yes
USE_KDELIBS_VER=	3
USE_GMAKE=		yes

.ifndef (WITHOUT_GSTREAMER)
USE_GSTREAMER=		yes
PLIST_SUB+=		NOGSTREAMER="@comment "
.else
PLIST_SUB+=		NOGSTREAMER=""
.endif

USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"
CONFIGURE_TARGET=

MAN1=		kaffeine.1
MANLANG=	"" de

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xorg
CONFIGURE_ARGS+=	--with-xorg
.endif

.ifdef (WITHOUT_GSTREAMER)
CONFIGURE_ARGS+=	--without-gstreamer
.endif

.include <bsd.port.post.mk>
