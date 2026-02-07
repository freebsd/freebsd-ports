PORTNAME=	lograge
PORTVERSION=	0.14.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails-gitlab

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tame Rails' multi-line logging into a single line per request #'
WWW=		https://github.com/roidrage/lograge

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionpack-gitlab>=4:www/rubygem-actionpack-gitlab \
		rubygem-activesupport-gitlab>=4:devel/rubygem-activesupport-gitlab \
		rubygem-railties-gitlab>=4:www/rubygem-railties-gitlab \
		rubygem-request_store>=1.0<2:devel/rubygem-request_store

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
