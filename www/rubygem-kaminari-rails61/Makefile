# Created by: Steve Wills <swills@FreeBSD.org>

PORTNAME=	kaminari
PORTVERSION=	1.2.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sophisticated paginator for Rails 4+

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport61>=4.1.0:devel/rubygem-activesupport61 \
		rubygem-kaminari-actionview-rails61>=${PORTVERSION}:www/rubygem-kaminari-actionview-rails61 \
		rubygem-kaminari-activerecord-rails61>=${PORTVERSION}:www/rubygem-kaminari-activerecord-rails61 \
		rubygem-kaminari-core>=${PORTVERSION}:www/rubygem-kaminari-core

USES=		cpe gem
CPE_VENDOR=	${PORTNAME}_project
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
