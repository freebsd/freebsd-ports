PORTNAME=	geminabox
PORTVERSION=	4.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sinatra based gem hosting app
WWW=		https://tomlea.co.uk/posts/gem-in-a-box/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-builder>=0:devel/rubygem-builder \
		rubygem-compact_index>=0.15<1:devel/rubygem-compact_index \
		rubygem-faraday>=1.0<3.0:www/rubygem-faraday \
		rubygem-httpclient>=2.2.7:www/rubygem-httpclient \
		rubygem-nesty>=0:devel/rubygem-nesty \
		rubygem-reentrant_flock>=0:devel/rubygem-reentrant_flock \
		rubygem-rss>=0.3<1:www/rubygem-rss \
		rubygem-rubygems-generate_index>=1.1<2:devel/rubygem-rubygems-generate_index \
		rubygem-sinatra>=4.0<5:www/rubygem-sinatra

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	geminabox_project

.include <bsd.port.mk>
