# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	tumblr_client
PORTVERSION=	0.8.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	mmoll@FreeBSD.org
COMMENT=	Ruby Wrapper for the Tumblr v2 API

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-faraday>=0.9.0:${PORTSDIR}/www/rubygem-faraday \
		rubygem-faraday_middleware>=0.9.1:${PORTSDIR}/www/rubygem-faraday_middleware \
		rubygem-json>0:${PORTSDIR}/devel/rubygem-json \
		rubygem-mime-types>0:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-oauth>0:${PORTSDIR}/net/rubygem-oauth \
		rubygem-simple_oauth>0:${PORTSDIR}/net/rubygem-simple_oauth

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/tumblr

.include <bsd.port.mk>
