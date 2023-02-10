PORTNAME=	kaminari-activerecord
PORTVERSION=	1.2.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Kaminari Active Record adapter
WWW=		https://github.com/kaminari/kaminari/tree/master/kaminari-activerecord

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activerecord4>=0:databases/rubygem-activerecord4 \
		rubygem-kaminari-core>=${PORTVERSION}:www/rubygem-kaminari-core

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
