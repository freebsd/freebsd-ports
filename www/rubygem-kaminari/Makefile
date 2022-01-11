# Created by: Steve Wills <swills@FreeBSD.org>

PORTNAME=	kaminari
PORTVERSION=	1.2.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sophisticated paginator for Rails 4+

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport4>=4.1.0:devel/rubygem-activesupport4 \
		rubygem-kaminari-actionview>=${PORTVERSION}:www/rubygem-kaminari-actionview \
		rubygem-kaminari-activerecord>=${PORTVERSION}:www/rubygem-kaminari-activerecord \
		rubygem-kaminari-core>=${PORTVERSION}:www/rubygem-kaminari-core

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	kaminari_project

.include <bsd.port.mk>
