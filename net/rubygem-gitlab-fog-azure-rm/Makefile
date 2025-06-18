PORTNAME=	gitlab-fog-azure-rm
PORTVERSION=	2.2.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Stripped-down fork that enables Azure Blob Storage
WWW=		https://gitlab.com/gitlab-org/gitlab-fog-azure-rm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday-gitlab>=2.0<3:www/rubygem-faraday-gitlab \
		rubygem-faraday-follow_redirects-gitlab>=0.3.0<0.4:www/rubygem-faraday-follow_redirects-gitlab \
		rubygem-faraday-net_http_persistent-gitlab>=2.0<3:www/rubygem-faraday-net_http_persistent-gitlab \
		rubygem-fog-core-gitlab>=2.1<3:devel/rubygem-fog-core-gitlab \
		rubygem-fog-json-gitlab>=1.2<2:devel/rubygem-fog-json-gitlab \
		rubygem-mime-types-gitlab>=0:misc/rubygem-mime-types-gitlab \
		rubygem-net-http-persistent>=4.0<5:www/rubygem-net-http-persistent \
		rubygem-nokogiri>=1.10.8<2:textproc/rubygem-nokogiri

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
