# Created by: Philip M. Gollucci <pgollucci@p6m7g8.com>
# $FreeBSD$

PORTNAME=	geminabox
PORTVERSION=	0.12.4
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sinatra based gem hosting app

LICENSE=	MIT

RUN_DEPENDS=	rubygem-builder32>=0:${PORTSDIR}/devel/rubygem-builder32 \
		rubygem-faraday>=0:${PORTSDIR}/www/rubygem-faraday \
		rubygem-httpclient>=2.2.7:${PORTSDIR}/www/rubygem-httpclient \
		rubygem-nesty>=0:${PORTSDIR}/devel/rubygem-nesty \
		rubygem-sinatra>=1.2.7:${PORTSDIR}/www/rubygem-sinatra

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
