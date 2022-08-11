PORTNAME=	gollum
PORTVERSION=	5.2.3
PORTREVISION=	2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sirl33tname@gmail.com
COMMENT=	Simple wiki system built on top of Git

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git \
		rubygem-gemojione>=4.1<5:graphics/rubygem-gemojione \
		rubygem-gollum-lib>=5.1<6:www/rubygem-gollum-lib \
		rubygem-kramdown>=2.3<3:textproc/rubygem-kramdown \
		rubygem-kramdown-parser-gfm>=1.1.0<1.2:textproc/rubygem-kramdown-parser-gfm \
		rubygem-mustache-sinatra>=1.0<2:devel/rubygem-mustache-sinatra \
		rubygem-octicons>=12.0:misc/rubygem-octicons \
		rubygem-rss>=0.2.9<0.3:www/rubygem-rss \
		rubygem-sass>=3.5<4:textproc/rubygem-sass \
		rubygem-sinatra>=2.0<3:www/rubygem-sinatra \
		rubygem-sinatra-contrib>=2.0<3:www/rubygem-sinatra-contrib \
		rubygem-sprockets3>=3.7<4:devel/rubygem-sprockets3 \
		rubygem-sprockets-helpers>=1.2<2:devel/rubygem-sprockets-helpers \
		rubygem-uglifier>=4.2<5:www/rubygem-uglifier \
		rubygem-useragent>=0.16.2<0.17:devel/rubygem-useragent \
		rubygem-webrick>=1.7<2:www/rubygem-webrick \

USES=		cpe gem
CPE_VENDOR=	${PORTNAME}_project
USE_RUBY=	yes
USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes

PLIST_FILES=	bin/gollum \
		bin/gollum-migrate-tags
PLIST_DIRS=	${WWWDIR}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/gollum

.include <bsd.port.mk>
