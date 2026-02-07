PORTNAME=	kaminari
PORTVERSION=	1.2.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails70

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sophisticated paginator for Rails 4+
WWW=		https://github.com/kaminari/kaminari

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport70>=4.1.0:devel/rubygem-activesupport70 \
		rubygem-kaminari-actionview-rails70>=${PORTVERSION}:www/rubygem-kaminari-actionview-rails70 \
		rubygem-kaminari-activerecord-rails70>=${PORTVERSION}:www/rubygem-kaminari-activerecord-rails70 \
		rubygem-kaminari-core>=${PORTVERSION}:www/rubygem-kaminari-core

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	kaminari_project

.include <bsd.port.mk>
