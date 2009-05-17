# New ports collection makefile for:	mod_authenticache
# Date created:				Fri Oct  10
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	mod_authenticache
PORTVERSION=	2.0.8
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://killa.net/infosec/${PORTNAME}/
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A generic credential caching module for Apache 2.0.x

MAKE_JOBS_SAFE=  yes

USE_GMAKE=	YES
USE_APACHE=	2.0
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

post-patch:
		${REINPLACE_CMD} -e 's|VERSION|\"${PORTVERSION}\"|' ${WRKSRC}/${PORTNAME}.c	

.include <bsd.port.mk>
