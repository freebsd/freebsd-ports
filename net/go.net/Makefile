# Created by: Julien Laffaye <jlaffaye@FreeBSD.org>
# $FreeBSD$

PORTNAME=	go.net
PORTVERSION=	20120502
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	http://jlaffaye.net/ LOCAL/jlaffaye

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Additional Net packages for Go

GO_PKGNAME=	code.google.com/p/go.net
GO_TARGET=	${GO_PKGNAME}/dict	\
		${GO_PKGNAME}/spdy	\
		${GO_PKGNAME}/websocket

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
