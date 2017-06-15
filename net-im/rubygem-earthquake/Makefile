# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PORTNAME=	earthquake
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	net-im rubygems
MASTER_SITES=	RG

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	Terminal based Twitter client with Twitter streaming API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport4>=4.0:devel/rubygem-activesupport4 \
		rubygem-awesome_print>=0:devel/rubygem-awesome_print \
		rubygem-i18n>=0:devel/rubygem-i18n \
		rubygem-jugyo-twitter_oauth>=0.5.0.pre5:security/rubygem-jugyo-twitter_oauth \
		rubygem-launchy>=0:devel/rubygem-launchy \
		rubygem-notify>=0:devel/rubygem-notify \
		rubygem-oauth>=0:net/rubygem-oauth \
		rubygem-slop>=3.4.0:devel/rubygem-slop \
		rubygem-twitter-stream>=0:net/rubygem-twitter-stream

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/earthquake

.include <bsd.port.mk>
