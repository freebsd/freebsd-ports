# New ports collection makefile for:	gucharmap
# Date created:				02 Mar 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gucharmap
PORTVERSION=	0.2
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gucharmap

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	A Unicode/ISO10646 character map and font viewer

LIB_DEPEND=	gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
	       	LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/libdata/pkgconfig/libgnomeui-2.0.pc) || \
	defined(WITH_GNOME)
LIB_DEPENDS+=	gnomeui-2.200:${PORTSDIR}/x11-toolkits/libgnomeui
PKGNAMESUFFIX=	-gnome
.else
CONFIGURE_ARGS=	--disable-gnome
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
