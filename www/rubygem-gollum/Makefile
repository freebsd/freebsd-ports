PORTNAME=	gollum
DISTVERSION=	6.1.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sirl33tname@gmail.com
COMMENT=	Simple wiki system built on top of Git
WWW=		https://github.com/gollum/gollum

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git \
		rubygem-gemojione>=4.1<5:graphics/rubygem-gemojione \
		rubygem-gollum-lib>=6.0<7:www/rubygem-gollum-lib \
		rubygem-i18n>=1.8:devel/rubygem-i18n \
		rubygem-kramdown>=2.3<3:textproc/rubygem-kramdown \
		rubygem-kramdown-parser-gfm>=1.1.0<1.2:textproc/rubygem-kramdown-parser-gfm \
		rubygem-mustache-sinatra>=2.0<3:devel/rubygem-mustache-sinatra \
		rubygem-octicons>=19.0:misc/rubygem-octicons \
		rubygem-rdoc>=6:devel/rubygem-rdoc \
		rubygem-rss>=0.2.9:www/rubygem-rss \
		rubygem-sinatra>=4.0.0<5:www/rubygem-sinatra \
		rubygem-sinatra-contrib>=4.0.0<5:www/rubygem-sinatra-contrib \
		rubygem-sprockets>=4.1<5:devel/rubygem-sprockets \
		rubygem-sprockets-helpers>=1.2<2:devel/rubygem-sprockets-helpers \
		rubygem-useragent>=0.16.2<0.17:devel/rubygem-useragent \
		rubygem-webrick>=1.7<2:www/rubygem-webrick \
		rubygem-rackup>=2.1.0<3:www/rubygem-rackup

USES=		cpe gem shebangfix
CPE_VENDOR=	${PORTNAME}_project
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	docker-run.sh
NO_ARCH=	yes

PLIST_DIRS=	${WWWDIR}
PLIST_FILES=	bin/gollum \
		bin/gollum-migrate-tags

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/gollum

.include <bsd.port.mk>
