# $FreeBSD$

PORTNAME=	nats
PORTVERSION=	0.9.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Messaging system written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
GO_PKGNAME=	github.com/nats-io/gnatsd
USE_GITHUB=	yes
GH_ACCOUNT=	nats-io
GH_PROJECT=	gnatsd
PLIST_FILES=	bin/gnatsd

USE_RC_SUBR=	gnatsd.sh

.include <bsd.port.mk>
