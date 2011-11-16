# New ports collection makefile for:	rubygem-oauth2
# Date created:		2011-10-18
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	oauth2
PORTVERSION=	0.5.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A Ruby wrapper for the OAuth 2.0 protocol

RUN_DEPENDS=	rubygem-faraday>=0.7.4:${PORTSDIR}/www/rubygem-faraday \
		rubygem-multi_json>=1.0.3:${PORTSDIR}/devel/rubygem-multi_json

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
