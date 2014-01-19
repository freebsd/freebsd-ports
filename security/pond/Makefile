# $FreeBSD$

PORTNAME=	pond
PORTVERSION=	20140118
CATEGORIES=	security
MASTER_SITES=	http://c-s.li/ports/
DISTFILES=	pond-20140118.tar.gz \
		go-gtk-20131128.tar.gz \
		ed25519-20131225.tar.gz

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Forward secure, asynchronous messenger -- Server Only

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/code.google.com/p/go.crypto/bcrypt.a:${PORTSDIR}/security/go.crypto \
		${LOCALBASE}/${GO_LIBDIR}/code.google.com/p/goprotobuf/proto.a:${PORTSDIR}/devel/goprotobuf \
		${LOCALBASE}/${GO_LIBDIR}/code.google.com/p/go.net/dict.a:${PORTSDIR}/net/go.net

BROKEN=		Experimental. Know what you do!
PLIST_FILES=	bin/server
# USE_GNOME=	gtk30
GO_PKGNAME=	github.com/agl/pond
GO_TARGET=	${GO_PKGNAME}/server
#		${GO_PKGNAME}/client

post-extract:
	@${MKDIR} ${GO_WRKSRC:H}
	@${LN} -sf ${WRKSRC} ${GO_WRKSRC}
	@${LN} -sf ${WRKDIR}/go-gtk-20131128 ${GO_WRKDIR_SRC}/github.com/agl/go-gtk
	@${LN} -sf ${WRKDIR}/ed25519-20131225 ${GO_WRKDIR_SRC}/github.com/agl/ed25519

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
