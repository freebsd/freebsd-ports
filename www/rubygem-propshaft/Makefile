PORTNAME=	propshaft
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Deliver assets for Rails
WWW=		https://github.com/rails/propshaft

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack80>=7.0.0:www/rubygem-actionpack80 \
		rubygem-activesupport80>=7.0.0:devel/rubygem-activesupport80 \
		rubygem-rack>=0,3:www/rubygem-rack \
		rubygem-railties80>=7.0.0:www/rubygem-railties80

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
