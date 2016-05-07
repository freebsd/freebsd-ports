# Created by: mat@FreeBSD.org
# $FreeBSD$

PORTNAME=	epp-client-afnic
PORTVERSION=	0.15.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mat@FreeBSD.org
COMMENT=	AFNIC EPP client library

LICENSE=	MIT

RUN_DEPENDS=	rubygem-builder>=2.1.2:devel/rubygem-builder \
		rubygem-nokogiri>=1.4:textproc/rubygem-nokogiri \
		rubygem-epp-client-base=${PORTVERSION}:net/rubygem-epp-client-base \
		rubygem-epp-client-rgp=${PORTVERSION}:net/rubygem-epp-client-rgp \
		rubygem-epp-client-secdns=${PORTVERSION}:net/rubygem-epp-client-secdns \

USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
