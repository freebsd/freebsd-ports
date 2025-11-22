PORTNAME=	passman
PORTVERSION=	2.4.12
CATEGORIES=	security
MASTER_SITES=	https://releases.passman.cc/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Full featured password manager for Nextcloud
WWW=		https://passman.cc

LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream unmaintained
EXPIRATION_DATE=2025-12-31

NEXTCLOUD_RUN_DEPENDS=	26

USES=		nextcloud php:flavors

.include <bsd.port.mk>
