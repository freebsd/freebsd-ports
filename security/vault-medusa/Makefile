PORTNAME=	vault-medusa
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	security
DISTNAME=	medusa

MAINTAINER=	dereckson@gmail.com
COMMENT=	Exporter for Vault data
WWW=		https://github.com/jonasvinther/medusa

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/jonasvinther/medusa
GO_TARGET=	${PORTNAME}:medusa

CONFLICTS_INSTALL=	medusa-*

PLIST_FILES=	bin/medusa

.include <bsd.port.mk>
