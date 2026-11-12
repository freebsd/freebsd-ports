PORTNAME=	kaminari
PORTVERSION=	1.3.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails52

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sophisticated paginator for Rails 4+
WWW=		https://github.com/kaminari/kaminari

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport52>=4.1.0:devel/rubygem-activesupport52 \
		rubygem-kaminari-actionview-rails52>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-kaminari-actionview-rails52 \
		rubygem-kaminari-activerecord-rails52>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-kaminari-activerecord-rails52 \
		rubygem-kaminari-core>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-kaminari-core

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	kaminari_project

.include <bsd.port.mk>
