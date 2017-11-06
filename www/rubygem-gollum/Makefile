# Created by: Sir l33tname <sirl33tname@gmail.com>
# $FreeBSD$

PORTNAME=	gollum
PORTVERSION=	4.1.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sirl33tname@gmail.com
COMMENT=	Gollum is a simple wiki system built on top of Git

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git \
		rubygem-gemojione>=3.2:graphics/rubygem-gemojione \
		rubygem-gollum-lib>=4.2.7:www/rubygem-gollum-lib \
		rubygem-kramdown>=1.9:textproc/rubygem-kramdown \
		rubygem-mustache0>=0.99.5:devel/rubygem-mustache0 \
		rubygem-sinatra1>=1.4.4:www/rubygem-sinatra1 \
		rubygem-useragent>=0.16.2:devel/rubygem-useragent

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes
USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/gollum
PLIST_DIRS=     %%WWWDIR%%

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/gollum

.include <bsd.port.mk>
