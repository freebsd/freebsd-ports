PORTNAME=	activeresource
PORTVERSION=	6.1.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Coherent wrapper object-relational mapping for REST web services
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/activeresource

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activemodel71>=6.0:databases/rubygem-activemodel71 \
		rubygem-activemodel-serializers-xml>=1.0<2:databases/rubygem-activemodel-serializers-xml \
		rubygem-activesupport71>=6.0:devel/rubygem-activesupport71

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	active_resource

.include <bsd.port.mk>
