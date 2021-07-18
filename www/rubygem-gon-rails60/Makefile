PORTNAME=	gon
PORTVERSION=	6.4.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails60

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Framework to pass data to JS easily

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack60>=3.0.20:www/rubygem-actionpack60 \
		rubygem-i18n>=0.7:devel/rubygem-i18n \
		rubygem-multi_json>=0:devel/rubygem-multi_json \
		rubygem-request_store>=1.0:devel/rubygem-request_store

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
