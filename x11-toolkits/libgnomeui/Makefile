# Created by: Joe Marcus Clarke <marcus@FreBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/libgnomeui/Makefile,v 1.129 2010/09/27 20:16:41 kwm Exp $

PORTNAME=	libgnomeui
PORTVERSION=	2.24.4
PORTREVISION?=	3
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libraries for the GNOME GUI, a GNU desktop environment

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS+=	libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring \
		libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme

USE_XORG=	sm
USES=		bison pathfix gettext gmake pkgconfig
USE_GNOME=	gnomeprefix gnomehier libbonoboui ltverhack \
		referencehack gvfs
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnomeui-2.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libglade/2.0/libgnome.so

.include <bsd.port.mk>

.endif
