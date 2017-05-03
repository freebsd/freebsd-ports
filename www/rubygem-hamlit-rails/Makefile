# $FreeBSD$

PORTNAME=	hamlit-rails
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Hamlit (haml) generators for Rails 4

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport4>=4.0.1:devel/rubygem-activesupport4 \
		rubygem-actionpack4>=4.0.1:www/rubygem-actionpack4 \
		rubygem-hamlit>=1.2.0:www/rubygem-hamlit \
		rubygem-railties4>=4.0.1:www/rubygem-railties4

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix
bash_CMD=	${SH}
SHEBANG_FILES=	bin/setup

.include <bsd.port.mk>
