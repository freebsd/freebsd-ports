PORTNAME=	bullet_train-roles
PORTVERSION=	1.38.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Yaml-backed ApplicationHash for CanCan Roles
WWW=		https://github.com/bullet-train-co/bullet_train-core/tree/main/bullet_train-roles

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-active_hash>=3.3.1:devel/rubygem-active_hash \
		rubygem-activesupport81>=0:devel/rubygem-activesupport81 \
		rubygem-cancancan>=0:security/rubygem-cancancan

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
