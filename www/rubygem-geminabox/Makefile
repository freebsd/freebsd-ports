# Created by: Philip M. Gollucci <pgollucci@p6m7g8.com>
# $FreeBSD$

PORTNAME=	geminabox
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sinatra based gem hosting app

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-builder>=0:devel/rubygem-builder \
		rubygem-faraday0>=0:www/rubygem-faraday0 \
		rubygem-httpclient>=2.2.7:www/rubygem-httpclient \
		rubygem-nesty>=0:devel/rubygem-nesty \
		rubygem-reentrant_flock>=0:devel/rubygem-reentrant_flock \
		rubygem-sinatra>=1.2.7:www/rubygem-sinatra

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
