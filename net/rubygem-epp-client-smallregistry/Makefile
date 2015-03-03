# Created by: mat@FreeBSD.org
# $FreeBSD$

PORTNAME=	epp-client-smallregistry
PORTVERSION=	0.13.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Smallregistry EPP client library

LICENSE=	MIT

RUN_DEPENDS=	rubygem-builder>=2.1.2:${PORTSDIR}/devel/rubygem-builder \
		rubygem-nokogiri14>=1.4:${PORTSDIR}/textproc/rubygem-nokogiri14 \
		rubygem-epp-client-base=${PORTVERSION}:${PORTSDIR}/net/rubygem-epp-client-base \
		rubygem-epp-client-secdns=${PORTVERSION}:${PORTSDIR}/net/rubygem-epp-client-secdns \

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
