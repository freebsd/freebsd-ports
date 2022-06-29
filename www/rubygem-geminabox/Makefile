# Created by: Philip M. Gollucci <pgollucci@p6m7g8.com>

PORTNAME=	geminabox
PORTVERSION=	2.0.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sinatra based gem hosting app

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-builder>=0:devel/rubygem-builder \
		rubygem-faraday1>=0<2.0:www/rubygem-faraday1 \
		rubygem-httpclient>=2.2.7:www/rubygem-httpclient \
		rubygem-nesty>=0:devel/rubygem-nesty \
		rubygem-reentrant_flock>=0:devel/rubygem-reentrant_flock \
		rubygem-rss>=0:www/rubygem-rss \
		rubygem-sinatra>=1.2.7:www/rubygem-sinatra

USES=		cpe gem
CPE_VENDOR=	${PORTNAME}_project
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
