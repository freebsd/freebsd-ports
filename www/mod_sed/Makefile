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

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${BUILD_DEPENDS}

APXS?=		${LOCALBASE}/sbin/apxs

MAKE_ARGS=	APXS=${APXS}

.include <bsd.port.mk>
