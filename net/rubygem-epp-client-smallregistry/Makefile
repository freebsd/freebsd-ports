# $FreeBSD$

PORTNAME=	epp-client-smallregistry
PORTVERSION=	0.15.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Smallregistry EPP client library

LICENSE=	MIT

RUN_DEPENDS=	rubygem-builder>=2.1.2:devel/rubygem-builder \
		rubygem-epp-client-base=${PORTVERSION}:net/rubygem-epp-client-base \
		rubygem-epp-client-secdns=${PORTVERSION}:net/rubygem-epp-client-secdns \
		rubygem-nokogiri>=1.4:textproc/rubygem-nokogiri

USES=		gem

.include <bsd.port.mk>
