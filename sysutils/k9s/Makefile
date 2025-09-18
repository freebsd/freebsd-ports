PORTNAME=	k9s
DISTVERSIONPREFIX=	v
DISTVERSION=	0.50.10
CATEGORIES=	sysutils

MAINTAINER=	gogolok@gmail.com
COMMENT=	Kubernetes command-line tool
WWW=		https://github.com/derailed/k9s

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/derailed/k9s
GO_BUILDFLAGS=	-ldflags="-X github.com/derailed/k9s/cmd.version=${DISTVERSIONFULL} \
		-X github.com/derailed/k9s/cmd.date=$$(date +'%Y-%m-%dT%H:%M:%SZ') \
		-X github.com/derailed/k9s/cmd.commit=4f5c1a1105974e8bbff9a0e145c9a8f6b642a21d"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
