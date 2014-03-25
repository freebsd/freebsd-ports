# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/textproc/gtkspell/Makefile,v 1.2 2006/09/10 00:51:13 mezz Exp $

PORTNAME=	gtkspell
PORTVERSION=	2.0.16
PORTREVISION?=	4
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	marcus

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GTK+ 2 spell checking component

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant

USE_GNOME=	gnomeprefix gtk20 intlhack
USES=		gettext gmake pkgconfig pathfix
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|docs||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
