# $FreeBSD$

PORTNAME=	hamlit-rails
PORTVERSION=	0.2.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Hamlit (haml) generators for Rails 5

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport5>=0:devel/rubygem-activesupport5 \
		rubygem-actionpack5>=0:www/rubygem-actionpack5 \
		rubygem-hamlit>=1.2.0:www/rubygem-hamlit \
		rubygem-railties5>=0:www/rubygem-railties5

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	bin/setup
bash_CMD=	${SH}

.include <bsd.port.mk>
