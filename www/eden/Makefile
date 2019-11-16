# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eden
PORTVERSION=	0.7.4
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Interact with any Open Service Broker API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes

GH_ACCOUNT=	starkandwayne

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/eden

.include <bsd.port.mk>
