# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sift
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and powerful open source alternative to grep

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

PLIST_FILES=	bin/sift

GH_ACCOUNT=	svent
GH_TUPLE=	golang:crypto:df01cb2:golang_crypto/../src/golang.org/x/crypto \
		golang:sys:e8e3143:golang_sys/../src/golang.org/x/sys \
		svent:go-flags:4bcbad3:svent_goflags/../src/github.com/svent/go-flags \
		svent:go-nbreader:7cef48d:svent_gonbreader/../src/github.com/svent/go-nbreader
USE_GITHUB=	yes

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/sift ${STAGEDIR}${PREFIX}/bin/sift

.include <bsd.port.mk>
