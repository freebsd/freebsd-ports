PORTNAME=	gitlab-fog-azure-rm
PORTVERSION=	2.0.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Stripped-down fork that enables Azure Blob Storage
WWW=		https://gitlab.com/gitlab-org/gitlab-fog-azure-rm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday>=2.0<3:www/rubygem-faraday \
		rubygem-faraday-follow_redirects>=0.3.0<0.4:www/rubygem-faraday-follow_redirects \
		rubygem-faraday-net_http_persistent>=2.0<3:www/rubygem-faraday-net_http_persistent \
		rubygem-fog-core>=2.1<3:devel/rubygem-fog-core \
		rubygem-fog-json>=1.2<2:devel/rubygem-fog-json \
		rubygem-mime-types>=0:misc/rubygem-mime-types \
		rubygem-net-http-persistent>=4.0<5:www/rubygem-net-http-persistent \
		rubygem-nokogiri>=1.10.8<2:textproc/rubygem-nokogiri

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
