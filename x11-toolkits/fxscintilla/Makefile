# New ports collection makefile for:	fxscintilla
# Date created:				16 June 2004
# Whom:                 		Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	fxscintilla
PORTVERSION=	2.11.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Fox toolkit reimplementation of Scintilla editing widget

LIB_DEPENDS+=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16

USE_GNOME=	gnomehack pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
USE_LDCONFIG=	yes

.include <bsd.port.mk>
