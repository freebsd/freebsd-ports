# Created by: Steve Wills <swills@FreeBSD.org>

PORTNAME=	kaminari
PORTVERSION=	1.2.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sophisticated paginator for Rails 4+

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport50>=4.1.0:devel/rubygem-activesupport50 \
		rubygem-kaminari-actionview-rails50>=${PORTVERSION}:www/rubygem-kaminari-actionview-rails50 \
		rubygem-kaminari-activerecord-rails50>=${PORTVERSION}:www/rubygem-kaminari-activerecord-rails50 \
		rubygem-kaminari-core>=${PORTVERSION}:www/rubygem-kaminari-core

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	kaminari_project

.include <bsd.port.mk>
