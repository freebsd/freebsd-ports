# New ports collection makefile for:	mod_auth_any
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_auth_any
PORTVERSION=	1.5
CATEGORIES=	www
MASTER_SITES=	http://www.itlab.musc.edu/webNIS/dist/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module to use any command line program to authenticate a user

MAKE_JOBS_SAFE=  yes

USE_APACHE=	13+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/src

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} >= 20
AP_EXTRAS+=	-DWITH_APACHE2=1
.endif

.include <bsd.port.post.mk>
