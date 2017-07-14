# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oauth2
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	12

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby wrapper for the OAuth 2.0 protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday>=0.8:www/rubygem-faraday \
		rubygem-jwt>=1.0:www/rubygem-jwt \
		rubygem-multi_json>=1.3:devel/rubygem-multi_json \
		rubygem-multi_xml>=0.5:textproc/rubygem-multi_xml \
		rubygem-rack>=1.2:www/rubygem-rack

DEPRECATED=	Only created for www/gitlab; please use net/rubygem-oauth2 instead
EXPIRATION_DATE=	2017-07-31

PORTSCOUT=	limit:^1\.2\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
