PORTNAME=	dyff
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.2
CATEGORIES=	textproc

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Diff tool for YAML files, and sometimes JSON
WWW=		https://github.com/homeport/dyff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	homeport

GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/dyff

.include <bsd.port.mk>
