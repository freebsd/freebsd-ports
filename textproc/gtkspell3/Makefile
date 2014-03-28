# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkspell3
PORTVERSION=	3.0.4
CATEGORIES=	textproc gnome
MASTER_SITES=	SF/gtkspell/${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+ 3 spell checking component

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant

USE_GNOME=	gnomehier gnomeprefix gtk30 intlhack introspection:build
USES=		gettext gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|docs||' ${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgtkspell3-3.so.*

.include <bsd.port.mk>
