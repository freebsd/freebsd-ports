# $FreeBSD$

PORTNAME=	roadie-rails
PORTVERSION=	1.1.1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Helper for generating HTML mails in Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-railties4>=3.0:www/rubygem-railties4 \
		rubygem-roadie>=3.1:mail/rubygem-roadie

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
