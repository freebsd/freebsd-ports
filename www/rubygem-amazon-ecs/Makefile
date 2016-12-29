# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	amazon-ecs
PORTVERSION=	2.5.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Generic Amazon E-commerce REST API written in Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-nokogiri>=1.4:textproc/rubygem-nokogiri \
		rubygem-ruby-hmac>=0.3:security/rubygem-ruby-hmac

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
