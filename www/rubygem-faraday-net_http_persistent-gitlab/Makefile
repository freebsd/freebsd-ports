PORTNAME=	faraday-net_http_persistent
PORTVERSION=	2.3.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Faraday adapter for NetHttpPersistent
WWW=		https://github.com/lostisland/faraday-net_http_persistent

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday-gitlab>=2.5<3:www/rubygem-faraday-gitlab \
		rubygem-net-http-persistent>=4.0.4<5:www/rubygem-net-http-persistent

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
