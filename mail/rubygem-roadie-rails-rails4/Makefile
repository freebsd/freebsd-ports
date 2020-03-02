# $FreeBSD$

PORTNAME=	roadie-rails
PORTVERSION=	1.3.0
PORTREVISION=	1
PORTREVISION=	1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Helper for generating HTML mails in Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-railties4>=3.0<5.3:www/rubygem-railties4 \
		rubygem-roadie3>=3.1<4:mail/rubygem-roadie3

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	setup.sh

.include <bsd.port.mk>
