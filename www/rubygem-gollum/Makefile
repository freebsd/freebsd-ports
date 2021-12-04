# Created by: Sir l33tname <sirl33tname@gmail.com>

PORTNAME=	gollum
PORTVERSION=	5.2.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sirl33tname@gmail.com
COMMENT=	Simple wiki system built on top of Git

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git \
		rubygem-gemojione>=3.3.0:graphics/rubygem-gemojione \
		rubygem-gollum-lib>=5.1.3:www/rubygem-gollum-lib \
		rubygem-gollum-rugged_adapter>=1.0:www/rubygem-gollum-rugged_adapter \
		rubygem-kramdown>=2.3.1:textproc/rubygem-kramdown \
		rubygem-kramdown-parser-gfm>=1.1.0:textproc/rubygem-kramdown-parser-gfm \
		rubygem-mustache0>=0.99.5:devel/rubygem-mustache0 \
		rubygem-sinatra>=2.1.0:www/rubygem-sinatra \
		rubygem-sinatra-contrib>=2.1.0:www/rubygem-sinatra-contrib \
		rubygem-mustache-sinatra>=1.0.1:devel/rubygem-mustache-sinatra \
		rubygem-useragent>=0.16.2:devel/rubygem-useragent \
		rubygem-octicons>=12.0.0:misc/rubygem-octicons \
		rubygem-sprockets>=3.7:devel/rubygem-sprockets \
		rubygem-sass>=3.5:textproc/rubygem-sass \
		rubygem-uglifier>=4.1:www/rubygem-uglifier \
		rubygem-sprockets-helpers>=1.2:devel/rubygem-sprockets-helpers \
		rubygem-rss>=0.2.9:www/rubygem-rss \
		rubygem-webrick>=1.7.0:www/rubygem-webrick \

USES=		cpe gem
CPE_VENDOR=	${PORTNAME}_project
USE_RUBY=	yes
USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes

PLIST_FILES=	bin/gollum \
		bin/gollum-migrate-tags
PLIST_DIRS=	%%WWWDIR%%

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/gollum

.include <bsd.port.mk>
