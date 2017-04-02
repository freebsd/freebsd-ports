# $FreeBSD$

PORTNAME=	xmpp-client
PORTVERSION=	20170324
CATEGORIES=	net-im

MAINTAINER=	cs@FreeBSD.org
COMMENT=	XMPP client with OTR support

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/golang.org/x/crypto/bcrypt.a:security/go.crypto \
		${LOCALBASE}/${GO_LIBDIR}/golang.org/x/net/dict.a:net/go.net

USE_GITHUB=	yes
GH_ACCOUNT=	agl
GH_TAGNAME=	3030ad42ee2df255ffc108dc6d04893d9501c863
USES=		go
PLIST_FILES=	bin/xmpp-client
GO_PKGNAME=	github.com/agl/${PORTNAME}

.include <bsd.port.mk>
