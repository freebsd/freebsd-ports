# New ports collection makefile for:	kaffeine
# Date created:				2003-06-25
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kaffeine
PORTVERSION=	0.8
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kaffeine

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A xine-base multimedia player

LIB_DEPENDS=	xine.15:${PORTSDIR}/multimedia/libxine \
		mp3lame.0:${PORTSDIR}/audio/lame \
		cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia

USE_BZIP2=		yes
USE_KDELIBS_VER=	3
USE_GMAKE=		yes

.ifndef (WITHOUT_GSTREAMER)
USE_GSTREAMER80=	yes
PLIST_SUB+=		NOGSTREAMER=""
.else
PLIST_SUB+=		NOGSTREAMER="@comment "
.endif

USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"
CONFIGURE_TARGET=

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xorg
CONFIGURE_ARGS+=	--with-xorg
.endif

.ifdef (WITHOUT_GSTREAMER)
CONFIGURE_ARGS+=	--without-gstreamer
.endif

post-patch:
	${REINPLACE_CMD} -e "s,xx,," ${WRKSRC}/po/Makefile.in

.include <bsd.port.post.mk>
