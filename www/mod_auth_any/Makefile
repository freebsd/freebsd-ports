# New ports collection makefile for:	mod_auth_any
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_auth_any
PORTVERSION=	1.3.2
CATEGORIES=	www
MASTER_SITES=	http://www.itlab.musc.edu/webNIS/dist/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Apache module to use any command line program to authenticate a user

WANT_APACHE=	13
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/src

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"
.include <bsd.port.post.mk>
