# ex:ts=8
# New ports collection makefile for:	mod_sed
# Date created:			Aug 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mod_sed
PORTVERSION=	0.1
CATEGORIES=	www
MASTER_SITES=	http://www.happygiraffe.net/dist/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An apache module that embeds a copy of the sed(1) command

MAKE_JOBS_SAFE=  yes

USE_APACHE=	1.3
MAKE_ARGS=	APXS=${APXS}

.include <bsd.port.mk>
