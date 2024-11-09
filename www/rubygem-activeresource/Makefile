PORTNAME=	activeresource
PORTVERSION=	6.1.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Coherent wrapper object-relational mapping for REST web services
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/activeresource

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel72>=6.0:databases/rubygem-activemodel72 \
		rubygem-activemodel-serializers-xml>=1.0<2:databases/rubygem-activemodel-serializers-xml \
		rubygem-activesupport72>=6.0:devel/rubygem-activesupport72

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	active_resource

.include <bsd.port.mk>
