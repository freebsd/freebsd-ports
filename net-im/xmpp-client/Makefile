# $FreeBSD$

PORTNAME=	xmpp-client
PORTVERSION=	20160110
CATEGORIES=	net-im
MASTER_SITES=	http://c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	XMPP client with OTR support

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/golang.org/x/crypto/bcrypt.a:security/go.crypto \
		${LOCALBASE}/${GO_LIBDIR}/code.google.com/p/go.net/dict.a:net/go.net

USES=		go
PLIST_FILES=	bin/xmpp-client
GO_PKGNAME=	github.com/agl/${PORTNAME}

.include <bsd.port.mk>
