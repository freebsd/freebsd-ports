PORTNAME=	k9s
DISTVERSIONPREFIX=	v
DISTVERSION=	0.50.3
CATEGORIES=	sysutils

MAINTAINER=	gogolok@gmail.com
COMMENT=	Kubernetes command-line tool
WWW=		https://github.com/derailed/k9s

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.21,modules
GO_MODULE=	github.com/derailed/k9s
GO_BUILDFLAGS=	-ldflags="-X github.com/derailed/k9s/cmd.version=${DISTVERSIONFULL} \
		-X github.com/derailed/k9s/cmd.date=$$(date +'%Y-%m-%dT%H:%M:%SZ') \
		-X github.com/derailed/k9s/cmd.commit=594c2c6e4c8dce30e5553e84e4a16a3e55e36066"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
