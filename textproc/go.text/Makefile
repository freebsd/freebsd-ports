# $FreeBSD$

PORTNAME=	go.text
PORTVERSION=	20160702
PORTREVISION=	1
CATEGORIES=	textproc devel

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Additional textproc packages for Go

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	golang
GH_PROJECT=	text
GH_TAGNAME=	ce78b075c2fbd48520f4995b173eb9fe18b56ef3
USES=		go
GO_PKGNAME=	golang.org/x/text
GO_TARGET=	${GO_PKGNAME}/cases				\
		${GO_PKGNAME}/collate				\
		${GO_PKGNAME}/collate/build			\
		${GO_PKGNAME}/collate/colltab			\
		${GO_PKGNAME}/currency				\
		${GO_PKGNAME}/encoding				\
		${GO_PKGNAME}/encoding/charmap			\
		${GO_PKGNAME}/encoding/htmlindex		\
		${GO_PKGNAME}/encoding/ianaindex		\
		${GO_PKGNAME}/encoding/internal			\
		${GO_PKGNAME}/encoding/internal/identifier	\
		${GO_PKGNAME}/encoding/japanese			\
		${GO_PKGNAME}/encoding/korean			\
		${GO_PKGNAME}/encoding/simplifiedchinese	\
		${GO_PKGNAME}/encoding/traditionalchinese	\
		${GO_PKGNAME}/encoding/unicode			\
		${GO_PKGNAME}/internal				\
		${GO_PKGNAME}/internal/colltab			\
		${GO_PKGNAME}/internal/format			\
		${GO_PKGNAME}/internal/gen			\
		${GO_PKGNAME}/internal/number			\
		${GO_PKGNAME}/internal/stringset		\
		${GO_PKGNAME}/internal/tag			\
		${GO_PKGNAME}/internal/testtext			\
		${GO_PKGNAME}/internal/triegen			\
		${GO_PKGNAME}/internal/ucd			\
		${GO_PKGNAME}/internal/utf8internal		\
		${GO_PKGNAME}/language				\
		${GO_PKGNAME}/language/display			\
		${GO_PKGNAME}/message				\
		${GO_PKGNAME}/runes				\
		${GO_PKGNAME}/search				\
		${GO_PKGNAME}/secure				\
		${GO_PKGNAME}/secure/bidirule			\
		${GO_PKGNAME}/secure/precis			\
		${GO_PKGNAME}/transform				\
		${GO_PKGNAME}/unicode				\
		${GO_PKGNAME}/unicode/bidi			\
		${GO_PKGNAME}/unicode/cldr			\
		${GO_PKGNAME}/unicode/norm			\
		${GO_PKGNAME}/unicode/rangetable

.include <bsd.port.mk>
