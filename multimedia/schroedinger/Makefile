# New ports collection makefile for:	schroedinger
# Date created:		2008-06-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	schroedinger
PORTVERSION=	1.0.7
CATEGORIES=	multimedia
MASTER_SITES=	http://www.diracvideo.org/download/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-speed Dirac codec

LIB_DEPENDS=	oil:${PORTSDIR}/devel/liboil

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
WANT_GSTREAMER=	yes

OPTIONS=	GSTREAMER "Enable gstreamer plugin" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GSTREAMER)
CONFIGURE_ARGS+=	--disable-gstreamer
PLIST_SUB+=		GSTREAMER="@comment "
.else
USE_GSTREAMER=		yes
PLIST_SUB+=		GSTREAMER=""
.endif

post-patch:
	${REINPLACE_CMD} -e 's|^pkgconfigdir=.*|pkgconfigdir="\\$$(prefix)/libdata/pkgconfig"|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
