# New ports collection makefile for:	rubygem-oauth2
# Date created:		2011-10-18
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	oauth2
PORTVERSION=	0.8.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A Ruby wrapper for the OAuth 2.0 protocol

RUN_DEPENDS=	rubygem-faraday>=0.8:${PORTSDIR}/www/rubygem-faraday \
		rubygem-httpauth>=0.1:${PORTSDIR}/net/rubygem-httpauth \
		rubygem-jwt>=0.1.4:${PORTSDIR}/www/rubygem-jwt \
		rubygem-multi_json>=1.0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-rack>=1.2:${PORTSDIR}/www/rubygem-rack

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
