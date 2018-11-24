# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sift
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and powerful open source alternative to grep

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

PLIST_FILES=	bin/sift

GH_ACCOUNT=	svent
GH_TUPLE=	golang:crypto:3d3f9f4:golang_crypto/../src/golang.org/x/crypto \
		golang:sys:62eef0e:golang_sys/../src/golang.org/x/sys \
		svent:go-flags:4bcbad3:svent_goflags/../src/github.com/svent/go-flags \
		svent:go-nbreader:7cef48d:svent_gonbreader/../src/github.com/svent/go-nbreader
USE_GITHUB=	yes

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/sift ${STAGEDIR}${PREFIX}/bin/sift

.include <bsd.port.mk>
