PORTNAME=	kaminari-actionview
PORTVERSION=	1.2.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Kaminari Action View adapter
WWW=		https://github.com/kaminari/kaminari/tree/master/kaminari-actionview

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionview61>=0:devel/rubygem-actionview61 \
		rubygem-kaminari-core>=${PORTVERSION}:www/rubygem-kaminari-core

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
