# Created by: Julien Laffaye <jlaffaye@FreeBSD.org>
# $FreeBSD$

PORTNAME=	go.net
PORTVERSION=	20131227
CATEGORIES=	net devel
MASTER_SITES=	http://jlaffaye.net/ LOCAL/jlaffaye

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Additional Net packages for Go

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/code.google.com/p/go.text:textproc/go.text

USES=		go
GO_PKGNAME=	code.google.com/p/go.net
GO_TARGET=	${GO_PKGNAME}/dict		\
		${GO_PKGNAME}/html		\
		${GO_PKGNAME}/html/atom 	\
		${GO_PKGNAME}/html/charset	\
		${GO_PKGNAME}/idna		\
		${GO_PKGNAME}/ipv4		\
		${GO_PKGNAME}/ipv6		\
		${GO_PKGNAME}/netutil		\
		${GO_PKGNAME}/proxy		\
		${GO_PKGNAME}/publicsuffix	\
		${GO_PKGNAME}/spdy		\
		${GO_PKGNAME}/websocket

.include <bsd.port.mk>
