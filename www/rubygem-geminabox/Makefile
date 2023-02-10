PORTNAME=	geminabox
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sinatra based gem hosting app
WWW=		https://tomlea.co.uk/posts/gem-in-a-box/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-builder>=0:devel/rubygem-builder \
		rubygem-faraday>=1.0<3.0:www/rubygem-faraday \
		rubygem-httpclient>=2.2.7:www/rubygem-httpclient \
		rubygem-nesty>=0:devel/rubygem-nesty \
		rubygem-reentrant_flock>=0:devel/rubygem-reentrant_flock \
		rubygem-sinatra2>=2.0<3:www/rubygem-sinatra2

USES=		cpe gem
CPE_VENDOR=	${PORTNAME}_project

NO_ARCH=	yes

.include <bsd.port.mk>
