# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkspell3
PORTVERSION=	3.0.7
CATEGORIES=	textproc gnome
MASTER_SITES=	SF/gtkspell/${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+ 3 spell checking component

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libenchant.so:textproc/enchant

USE_GNOME=	gtk30 intlhack introspection:build
USES=		gettext gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGEt=	install-strip

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|docs||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
