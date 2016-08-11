# $FreeBSD$

PORTNAME=	xmpp-client
PORTVERSION=	20160717
CATEGORIES=	net-im

MAINTAINER=	cs@FreeBSD.org
COMMENT=	XMPP client with OTR support

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/golang.org/x/crypto/bcrypt.a:security/go.crypto \
		${LOCALBASE}/${GO_LIBDIR}/golang.org/x/net/dict.a:net/go.net

USE_GITHUB=	yes
GH_ACCOUNT=	agl
GH_TAGNAME=	abbf9020393e8caae3e8996a16ce48446e31cf0e
USES=		go
PLIST_FILES=	bin/xmpp-client
GO_PKGNAME=	github.com/agl/${PORTNAME}

.include <bsd.port.mk>
