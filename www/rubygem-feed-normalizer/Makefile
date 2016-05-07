# Created by: TERAMOTO Masahiro <markun@onohara.to>
# $FreeBSD$

PORTNAME=	feed-normalizer
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	www textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	markun@onohara.to
COMMENT=	Extensible wrapper for Atom and RSS parsers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

RUN_DEPENDS=	rubygem-hpricot>=0.6:www/rubygem-hpricot \
		rubygem-simple-rss>=1.1:www/rubygem-simple-rss

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
