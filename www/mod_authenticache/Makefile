# New ports collection makefile for:	mod_authenticache
# Date created:				Fri Oct  10
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	mod_authenticache
PORTVERSION=	2.0.8
CATEGORIES=	www
MASTER_SITES=	http://killa.net/infosec/mod_authenticache/
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A generic credential caching module for Apache 2.0.x

USE_APACHE=	YES
WITH_APACHE2=	YES
USE_GMAKE=	YES
MAKE_ENV+=	APXS="${APXS}"

.include <bsd.port.mk>
