PORTNAME=	k9s
DISTVERSIONPREFIX=	v
DISTVERSION=	0.28.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	gogolok@gmail.com
COMMENT=	Kubernetes command-line tool
WWW=		https://github.com/derailed/k9s

LICENSE=	APACHE20

USES=		go:modules

GO_MODULE=	github.com/derailed/k9s
GO_BUILDFLAGS=	-ldflags="-X github.com/derailed/k9s/cmd.version=${DISTVERSIONPREFIX}${DISTVERSION} \
		-X github.com/derailed/k9s/cmd.date=$$(date +'%Y-%m-%dT%H:%M:%SZ') \
		-X github.com/derailed/k9s/cmd.commit=4bbdaec56d621503ffac743e4fe29037f96841bd"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
