# New ports collection makefile for:	telepathy-haze
# Date created:		2007-10-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net-im/telepathy-haze/Makefile,v 1.3 2008/03/02 19:50:45 marcus Exp $

PORTNAME=	haze
PORTVERSION=	0.3.4
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-haze/
PKGNAMEPREFIX=	telepathy-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libpurple connection manager for telepathy

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	purple.7:${PORTSDIR}/net-im/libpurple \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib

USE_GNOME=	pkgconfig
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
WRKSRC=	${WRKDIR}/telepathy-${PORTNAME}-${DISTVERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN8=		telepathy-haze.8

.include <bsd.port.mk>
