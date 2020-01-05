# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sift
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
PORTREVISION=	6
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and powerful open source alternative to grep

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

PLIST_FILES=	bin/sift

GH_ACCOUNT=	svent
GH_TUPLE=	golang:crypto:53104e6:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:a1369af:golang_sys/vendor/golang.org/x/sys \
		svent:go-flags:4bcbad3:svent_goflags/vendor/github.com/svent/go-flags \
		svent:go-nbreader:7cef48d:svent_gonbreader/vendor/github.com/svent/go-nbreader
USE_GITHUB=	yes

.include <bsd.port.mk>
