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
MASTER_SITES=	http://www.myrddin.demon.co.uk/dist/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	An apache module that embeds a copy of the sed(1) command

BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${APACHE_PORT}

APXS?=		${LOCALBASE}/sbin/apxs
APACHE_PORT?=	${PORTSDIR}/www/apache13

MAKE_ARGS=	APXS=${APXS}

.include <bsd.port.mk>
