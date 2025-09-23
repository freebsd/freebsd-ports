PORTNAME=	k9s
DISTVERSIONPREFIX=	v
DISTVERSION=	0.50.12
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
		-X github.com/derailed/k9s/cmd.commit=09c1c0795051f443da6b75a11705e25c0c1c7c6b"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
