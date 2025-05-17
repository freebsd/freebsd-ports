PORTNAME=	kaminari
PORTVERSION=	1.2.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails-gitlab

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sophisticated paginator for Rails 4+
WWW=		https://github.com/kaminari/kaminari

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport-gitlab>=4.1.0:devel/rubygem-activesupport-gitlab \
		rubygem-kaminari-actionview-rails-gitlab>=${PORTVERSION}:www/rubygem-kaminari-actionview-rails-gitlab \
		rubygem-kaminari-activerecord-rails-gitlab>=${PORTVERSION}:www/rubygem-kaminari-activerecord-rails-gitlab \
		rubygem-kaminari-core>=${PORTVERSION}:www/rubygem-kaminari-core

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	kaminari_project

.include <bsd.port.mk>
