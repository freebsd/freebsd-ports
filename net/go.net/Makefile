# Created by: Julien Laffaye <jlaffaye@FreeBSD.org>
# $FreeBSD$

PORTNAME=	go.net
PORTVERSION=	20120502
CATEGORIES=	net devel
MASTER_SITES=	http://jlaffaye.net/ LOCAL/jlaffaye

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Additional Net packages for Go

GO_PKGNAME=	code.google.com/p/go.net
GO_TARGET=	${GO_PKGNAME}/dict	\
		${GO_PKGNAME}/spdy	\
		${GO_PKGNAME}/websocket

NO_STAGE=	yes
do-install:
	${MKDIR} ${GO_LOCAL_LIBDIR}/${GO_PKGNAME}
.for t in ${GO_TARGET}
	${INSTALL_DATA} ${GO_WRKDIR_PKG}/${t}.a \
		${GO_LOCAL_LIBDIR}/${GO_PKGNAME}
	${MKDIR} ${GO_LOCAL_SRCDIR}/${t}
	(cd ${GO_WRKDIR_SRC}/${t}/ && ${COPYTREE_SHARE} \* \
		${GO_LOCAL_SRCDIR}/${t})
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
