PORTNAME=	gon
PORTVERSION=	6.5.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Framework to pass data to JS easily
WWW=		https://github.com/gazay/gon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack-gitlab>=3.0.20:www/rubygem-actionpack-gitlab \
		rubygem-i18n>=0.7:devel/rubygem-i18n \
		rubygem-multi_json-gitlab>=0:devel/rubygem-multi_json-gitlab \
		rubygem-request_store>=1.0:devel/rubygem-request_store

USES=		cpe gem
CPE_VENDOR=	${PORTNAME}_project

NO_ARCH=	yes

.include <bsd.port.mk>
