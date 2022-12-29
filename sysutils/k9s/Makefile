PORTNAME=	k9s
DISTVERSIONPREFIX=	v
DISTVERSION=	0.26.7
CATEGORIES=	sysutils

MAINTAINER=	gogolok@gmail.com
COMMENT=	Kubernetes command-line tool
WWW=		https://github.com/derailed/k9s

LICENSE=	APACHE20

USES=		go:modules

GO_MODULE=	github.com/derailed/k9s
GO_BUILDFLAGS=	-ldflags="-X github.com/derailed/k9s/cmd.version=${PORTVERSION} \
		-X github.com/derailed/k9s/cmd.date=$$(date +'%Y-%m-%dT%H:%M:%SZ') \
		-X github.com/derailed/k9s/cmd.commit="""

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
