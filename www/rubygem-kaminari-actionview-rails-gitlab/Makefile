PORTNAME=	kaminari-actionview
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails-gitlab

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Kaminari Action View adapter
WWW=		https://github.com/kaminari/kaminari/tree/master/kaminari-actionview

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionview-gitlab>=0:devel/rubygem-actionview-gitlab \
		rubygem-kaminari-core-gitlab>=${PORTVERSION}:www/rubygem-kaminari-core-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
