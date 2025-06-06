PORTNAME=	k9s
DISTVERSIONPREFIX=	v
DISTVERSION=	0.50.6
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	gogolok@gmail.com
COMMENT=	Kubernetes command-line tool
WWW=		https://github.com/derailed/k9s

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
GO_MODULE=	github.com/derailed/k9s
GO_BUILDFLAGS=	-ldflags="-X github.com/derailed/k9s/cmd.version=${DISTVERSIONFULL} \
		-X github.com/derailed/k9s/cmd.date=$$(date +'%Y-%m-%dT%H:%M:%SZ') \
		-X github.com/derailed/k9s/cmd.commit=13cb55bb66272ac4c872a1f6bfa3e820d7d0ca5b"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
