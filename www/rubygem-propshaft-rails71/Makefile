PORTNAME=	propshaft
PORTVERSION=	1.2.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails71

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Deliver assets for Rails
WWW=		https://github.com/rails/propshaft

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack71>=7.0.0:www/rubygem-actionpack71 \
		rubygem-activesupport71>=7.0.0:devel/rubygem-activesupport71 \
		rubygem-rack>=0,3:www/rubygem-rack

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
