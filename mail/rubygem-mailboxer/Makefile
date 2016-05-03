# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mailboxer
PORTVERSION=	0.13.0
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Send messages inside a web application

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-carrierwave>=0.5.8:www/rubygem-carrierwave \
		rubygem-foreigner>=0.9.1:devel/rubygem-foreigner \
		rubygem-rails4>=3.2.0:www/rubygem-rails4

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
