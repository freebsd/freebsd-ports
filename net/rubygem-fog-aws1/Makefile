# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-aws
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support Amazon Web Services

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

DEPRECATED=	Obsoleted by update of www/gitlab. Please use net/rubygem-fog-aws instead.
EXPIRATION_DATE=	2018-06-30

RUN_DEPENDS=	rubygem-fog-core1>=1.38:devel/rubygem-fog-core1 \
		rubygem-fog-json>=1.0:devel/rubygem-fog-json \
		rubygem-fog-xml>=0.1:textproc/rubygem-fog-xml \
		rubygem-ipaddress>=0.8:net/rubygem-ipaddress

PORTSCOUT=	limit:^1\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
