PORTNAME=	jsonb_accessor
PORTVERSION=	1.4
CATEGORIES=	www devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Adds typed jsonb backed fields to your ActiveRecord models
WWW=		https://github.com/devmynd/jsonb_accessor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activerecord70>=6.1:databases/rubygem-activerecord70 \
		rubygem-activesupport70>=6.1:devel/rubygem-activesupport70 \
		rubygem-pg>=0.18.1:databases/rubygem-pg

USES=		gem shebangfix

SHEBANG_FILES=	bin/setup
NO_ARCH=	yes

.include <bsd.port.mk>
