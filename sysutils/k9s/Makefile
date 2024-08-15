PORTNAME=	k9s
DISTVERSIONPREFIX=	v
DISTVERSION=	0.32.4
PORTREVISION=	5
CATEGORIES=	sysutils

MAINTAINER=	gogolok@gmail.com
COMMENT=	Kubernetes command-line tool
WWW=		https://github.com/derailed/k9s

LICENSE=	APACHE20

USES=		go:1.21,modules
GO_MODULE=      github.com/derailed/k9s
GO_BUILDFLAGS=	-ldflags="-X github.com/derailed/k9s/cmd.version=${DISTVERSIONFULL} \
		-X github.com/derailed/k9s/cmd.date=$$(date +'%Y-%m-%dT%H:%M:%SZ') \
		-X github.com/derailed/k9s/cmd.commit=d3027c8f2916b23606f647f47b434b08fc34bdf8"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
