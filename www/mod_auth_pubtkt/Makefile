# New ports collection makefile for:	mod_auth_pubtkt
# Date created:				24 Mar 2009
# Whom:					Manuel Kasper <mk@neon1.net>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_pubtkt
PORTVERSION=	0.5
CATEGORIES=	www
MASTER_SITES=	https://neon1.net/mod_auth_pubtkt/
DISTNAME=	mod_auth_pubtkt-${PORTVERSION}

MAINTAINER=	mk@neon1.net
COMMENT=	An Apache module to provide public key ticket based authentication

USE_APACHE=	1.3+
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--apxs=${APXS}

.include <bsd.port.mk>
