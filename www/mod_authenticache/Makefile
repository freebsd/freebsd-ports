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

MAINTAINER=	clement@FreeBSD.org
COMMENT=	A generic credential caching module for Apache 2.0.x

USE_APACHE=	YES
WITH_APACHE2=	YES
USE_GMAKE=	YES
MAKE_ENV+=	APXS="${APXS}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
BROKEN=		"Does not compile on amd64 or ia64 (shared library objects must be compiled with -fPIC)"
.endif

.include <bsd.port.post.mk>
