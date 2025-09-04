PORTNAME=	sift
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
PORTREVISION=	52
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and powerful open source alternative to grep
WWW=		https://github.com/svent/sift

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

GO_PKGNAME=	github.com/svent/sift

PLIST_FILES=	bin/sift

USE_GITHUB=	yes
GH_ACCOUNT=	svent
GH_TUPLE=	golang:crypto:v0.25.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:v0.22.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.22.0:golang_term/vendor/golang.org/x/term \
		svent:go-flags:4bcbad3:svent_goflags/vendor/github.com/svent/go-flags \
		svent:go-nbreader:7cef48d:svent_gonbreader/vendor/github.com/svent/go-nbreader

.include <bsd.port.mk>
