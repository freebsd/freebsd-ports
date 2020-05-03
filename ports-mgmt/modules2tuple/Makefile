# $FreeBSD$

PORTNAME=	modules2tuple
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	ports-mgmt

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Generate GH_TUPLE from modules.txt

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	dmgk
GH_TUPLE=	sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff

GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
