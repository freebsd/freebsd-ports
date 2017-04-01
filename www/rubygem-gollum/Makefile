# Created by: Sir l33tname <sirl33tname@gmail.com>
# $FreeBSD$

PORTNAME=	gollum
PORTVERSION=	4.1.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sirl33tname@gmail.com
COMMENT=	Gollum is a simple wiki system built on top of Git

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gollum-lib>=4.0.1:www/rubygem-gollum-lib \
		rubygem-kramdown>=1.9:textproc/rubygem-kramdown \
		rubygem-sinatra>=1.4.4:www/rubygem-sinatra \
		rubygem-mustache0>=0.99.5:devel/rubygem-mustache0 \
		rubygem-gemojione2>=2.0:graphics/rubygem-gemojione2 \
		rubygem-useragent>=0.16.2:devel/rubygem-useragent \
		git>=0:devel/git

USE_RC_SUBR=	${PORTNAME}

post-stage:
		${MKDIR} ${STAGEDIR}${PREFIX}/www/gollum

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/gollum

PLIST_DIRS=     %%WWWDIR%%

.include <bsd.port.mk>
