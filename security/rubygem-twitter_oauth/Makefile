# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	twitter_oauth
PORTVERSION=	0.4.94
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Twitter OAuth REST API client library for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-json>=1.8.0:devel/rubygem-json \
		rubygem-mime-types>=1.16:misc/rubygem-mime-types \
		rubygem-oauth>=0.4.7:net/rubygem-oauth

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
