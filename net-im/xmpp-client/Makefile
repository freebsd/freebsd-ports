# $FreeBSD$

PORTNAME=	xmpp-client
PORTVERSION=	20151108
CATEGORIES=	net-im
MASTER_SITES=	http://c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	XMPP client with OTR support

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/code.google.com/p/go.crypto/bcrypt.a:${PORTSDIR}/security/go.crypto \
		${LOCALBASE}/${GO_LIBDIR}/code.google.com/p/go.net/dict.a:${PORTSDIR}/net/go.net

PLIST_FILES=	bin/xmpp-client
GO_PKGNAME=	github.com/agl/${PORTNAME}

post-extract:
	@${MKDIR} ${GO_WRKSRC:H}
	@${LN} -sf ${WRKSRC} ${GO_WRKSRC}


.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
