PORTNAME=	carrierwave
PORTVERSION=	3.0.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Upload files, map them to a range of ORMs, store on different backends
WWW=		https://github.com/carrierwaveuploader/carrierwave

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activemodel70>=6.0.0:databases/rubygem-activemodel70 \
		rubygem-activesupport70>=6.0.0:devel/rubygem-activesupport70 \
		rubygem-addressable>=2.6<3:www/rubygem-addressable \
		rubygem-image_processing>=1.1<2:graphics/rubygem-image_processing \
		rubygem-marcel>=1.0.0<1.1:devel/rubygem-marcel \
		rubygem-ssrf_filter>=1.0:security/rubygem-ssrf_filter

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	carrierwave_project

.include <bsd.port.mk>
