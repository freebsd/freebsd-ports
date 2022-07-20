PORTNAME=	kaminari
PORTVERSION=	1.2.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails60

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sophisticated paginator for Rails 4+

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport60>=4.1.0:devel/rubygem-activesupport60 \
		rubygem-kaminari-actionview-rails60>=${PORTVERSION}:www/rubygem-kaminari-actionview-rails60 \
		rubygem-kaminari-activerecord-rails60>=${PORTVERSION}:www/rubygem-kaminari-activerecord-rails60 \
		rubygem-kaminari-core>=${PORTVERSION}:www/rubygem-kaminari-core

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	kaminari_project

.include <bsd.port.mk>
