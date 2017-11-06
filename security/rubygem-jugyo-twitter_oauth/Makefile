# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PORTNAME=	jugyo-twitter_oauth
DISTVERSION=	0.5.0.pre5
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	Fork of Twitter OAuth REST API client library for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-json>=1.1.9:devel/rubygem-json \
		rubygem-mime-types>=1.16:misc/rubygem-mime-types \
		rubygem-oauth>=0.4.1:net/rubygem-oauth

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
