PORTNAME=	webmock
PORTVERSION=	3.26.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Allows stubbing HTTP requests and setting expectations on the requests
WWW=		https://github.com/bblimke/webmock

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.8.0:www/rubygem-addressable \
		rubygem-crack>=0.3.2:devel/rubygem-crack \
		rubygem-hashdiff>=0.4.0<2.0.0:devel/rubygem-hashdiff

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
