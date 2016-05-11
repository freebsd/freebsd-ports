# $FreeBSD$

PORTNAME=	nats
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Messaging system written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/golang.org/x/crypto/bcrypt.a:security/go.crypto

USES=		go
GO_PKGNAME=	github.com/nats-io/gnatsd
USE_GITHUB=	yes
GH_ACCOUNT=	nats-io
GH_PROJECT=	gnatsd
PLIST_FILES=	bin/gnatsd

.include <bsd.port.mk>
