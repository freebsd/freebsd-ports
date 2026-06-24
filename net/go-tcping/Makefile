PORTNAME=	tcping
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.1
PORTREVISION=	18
CATEGORIES=	net
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${PORTNAME}/${DISTVERSIONFULL}/:gomod
PKGNAMEPREFIX=	go-
DISTFILES=	go.mod:gomod

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line utility to ping TCP ports written in Go
WWW=		https://github.com/pouriyajamshidi/tcping

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	module modernc.org/sqlite only supported on aarch64 and amd64

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	pouriyajamshidi

GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/gotcping

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/gotcping

.include <bsd.port.mk>
