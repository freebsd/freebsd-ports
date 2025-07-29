PORTNAME=	propshaft
PORTVERSION=	1.2.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails72

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Deliver assets for Rails
WWW=		https://github.com/rails/propshaft

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack72>=7.0.0:www/rubygem-actionpack72 \
		rubygem-activesupport72>=7.0.0:devel/rubygem-activesupport72 \
		rubygem-rack>=0,3:www/rubygem-rack

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
