# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kaminari
PORTVERSION=	1.1.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails52

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sophisticated paginator for Rails 4+

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport52>0:devel/rubygem-activesupport52 \
		rubygem-kaminari-actionview-rails52>=${PORTVERSION}:www/rubygem-kaminari-actionview-rails52 \
		rubygem-kaminari-activerecord-rails52>=${PORTVERSION}:www/rubygem-kaminari-activerecord-rails52 \
		rubygem-kaminari-core>=${PORTVERSION}:www/rubygem-kaminari-core

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
