PORTNAME=	k9s
DISTVERSIONPREFIX=	v
DISTVERSION=	0.50.15
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	gogolok@gmail.com
COMMENT=	Kubernetes command-line tool
WWW=		https://github.com/derailed/k9s

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386

USES=		go:modules
GO_MODULE=	github.com/derailed/k9s
GO_BUILDFLAGS=	-ldflags="-X github.com/derailed/k9s/cmd.version=${DISTVERSIONFULL} \
		-X github.com/derailed/k9s/cmd.date=$$(date +'%Y-%m-%dT%H:%M:%SZ') \
		-X github.com/derailed/k9s/cmd.commit=72ea1d48513a467ccdbff8e238396a278c3f4dd6"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
