PORTNAME=	cloudinary
PORTVERSION=	2.3.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Client library for easily using the Cloudinary service
WWW=		https://cloudinary.com/ \
		https://cloudinary.com/documentation/rails_integration \
		https://github.com/cloudinary/cloudinary_gem

LICENSE=	MIT

RUN_DEPENDS=	rubygem-faraday>=2.0.1<3.0.0:www/rubygem-faraday \
		rubygem-faraday-follow_redirects>=0.3.0<0.4:www/rubygem-faraday-follow_redirects \
		rubygem-faraday-multipart>=1.0.4<2:www/rubygem-faraday-multipart \
		rubygem-ostruct>=0:devel/rubygem-ostruct

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
