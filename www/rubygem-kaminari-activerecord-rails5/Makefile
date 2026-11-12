PORTNAME=	kaminari-activerecord
PORTVERSION=	1.3.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Kaminari Active Record adapter
WWW=		https://github.com/kaminari/kaminari/tree/master/kaminari-activerecord

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activerecord5>=0:databases/rubygem-activerecord5 \
		rubygem-kaminari-core>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-kaminari-core

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
