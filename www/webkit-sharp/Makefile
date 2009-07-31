# New ports collection makefile for:	webkit-sharp
# Date created:		2008-09-01
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	webkit-sharp
PORTVERSION=	0.2
PORTREVISION=	1
#PORTEPOCH=	0
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.novell.com/pub/mono/sources/${PORTNAME}/
#MASTER_SITE_SUBDIR=
#PKGNAMEPREFIX=
#PKGNAMESUFFIX=
#DISTNAME=
#EXTRACT_SUFX=
#DISTFILES=
#DIST_SUBDIR=	${PORTNAME}
#EXTRACT_ONLY=

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono bindings for Webkit

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/webkit-1.0.pc:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtksharp20

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
