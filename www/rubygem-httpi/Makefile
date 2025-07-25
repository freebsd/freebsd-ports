PORTNAME=	httpi
PORTVERSION=	4.0.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Library for common HTTP client API
WWW=		https://github.com/savonrb/httpi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-mutex_m>0:devel/rubygem-mutex_m \
		rubygem-nkf>0:net/rubygem-nkf \
		rubygem-rack>=2.0:www/rubygem-rack \
		rubygem-socksify>=0:www/rubygem-socksify

NO_ARCH=	yes
USES=		gem

.include <bsd.port.mk>
