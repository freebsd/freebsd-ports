# $FreeBSD$

PORTNAME=	roadie-rails
PORTVERSION=	1.1.0
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Helper for generating HTML mails in Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-railties4>=4.2:${PORTSDIR}/www/rubygem-railties4 \
		rubygem-roadie>=3.1:${PORTSDIR}/mail/rubygem-roadie

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
