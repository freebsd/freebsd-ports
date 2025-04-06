PORTNAME=	k9s
DISTVERSIONPREFIX=	v
DISTVERSION=	0.40.10
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
		-X github.com/derailed/k9s/cmd.commit=35361bb23822761200fcc977653818faf054adad"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
