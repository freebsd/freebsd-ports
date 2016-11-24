# Created by: Julien Laffaye <jlaffaye@FreeBSD.org>
# $FreeBSD$

PORTNAME=	go.net
PORTVERSION=	20160708
PORTREVISION=	1
CATEGORIES=	net devel

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Additional Net packages for Go

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/golang.org/x/text/cases.a:textproc/go.text \
		go.crypto>=20160709:security/go.crypto

USE_GITHUB=	yes
GH_ACCOUNT=	golang
GH_PROJECT=	net
GH_TAGNAME=	f841c39de738b1d0df95b5a7187744f0e03d8112
USES=		go
GO_TARGET=	${GO_PKGNAME}/bpf               \
		${GO_PKGNAME}/context           \
		${GO_PKGNAME}/context/ctxhttp   \
		${GO_PKGNAME}/dict              \
		${GO_PKGNAME}/html              \
		${GO_PKGNAME}/html/atom         \
		${GO_PKGNAME}/html/charset      \
		${GO_PKGNAME}/http2             \
		${GO_PKGNAME}/http2/h2i         \
		${GO_PKGNAME}/http2/hpack       \
		${GO_PKGNAME}/icmp              \
		${GO_PKGNAME}/idna              \
		${GO_PKGNAME}/internal/iana     \
		${GO_PKGNAME}/ipv4              \
		${GO_PKGNAME}/ipv6              \
		${GO_PKGNAME}/lex/httplex       \
		${GO_PKGNAME}/netutil           \
		${GO_PKGNAME}/proxy             \
		${GO_PKGNAME}/publicsuffix      \
		${GO_PKGNAME}/route             \
		${GO_PKGNAME}/trace             \
		${GO_PKGNAME}/webdav            \
		${GO_PKGNAME}/websocket         \
		${GO_PKGNAME}/xsrftoken

GO_PKGNAME=	golang.org/x/net

.include <bsd.port.mk>
