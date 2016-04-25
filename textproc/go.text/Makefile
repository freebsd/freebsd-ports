# $FreeBSD$

PORTNAME=	go.text
PORTVERSION=	20131227
CATEGORIES=	textproc devel
MASTER_SITES=	http://jlaffaye.net/ LOCAL/jlaffaye

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Additional textproc packages for Go

LICENSE=	BSD3CLAUSE

USES=		go
GO_PKGNAME=	code.google.com/p/go.text
GO_TARGET=	${GO_PKGNAME}/cldr				\
		${GO_PKGNAME}/collate				\
		${GO_PKGNAME}/collate/build			\
		${GO_PKGNAME}/collate/colltab			\
		${GO_PKGNAME}/encoding				\
		${GO_PKGNAME}/encoding/charmap			\
		${GO_PKGNAME}/encoding/japanese			\
		${GO_PKGNAME}/encoding/korean			\
		${GO_PKGNAME}/encoding/simplifiedchinese	\
		${GO_PKGNAME}/encoding/traditionalchinese	\
		${GO_PKGNAME}/encoding/unicode			\
		${GO_PKGNAME}/language				\
		${GO_PKGNAME}/transform				\
		${GO_PKGNAME}/unicode/norm

.include <bsd.port.mk>
