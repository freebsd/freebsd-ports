PORTNAME=	swd
PORTVERSION=	2.0.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple Web Discovery Client Library
WWW=		https://github.com/nov/swd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport70>=3:devel/rubygem-activesupport70 \
		rubygem-attr_required>=0.0.5:devel/rubygem-attr_required \
		rubygem-faraday>=2.0<3:www/rubygem-faraday \
		rubygem-faraday-follow_redirects>=0:www/rubygem-faraday-follow_redirects

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
