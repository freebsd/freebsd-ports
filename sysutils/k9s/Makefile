PORTNAME=	k9s
DISTVERSIONPREFIX=	v
DISTVERSION=	0.50.18
CATEGORIES=	sysutils

MAINTAINER=	gogolok@gmail.com
COMMENT=	Kubernetes command-line tool
WWW=		https://github.com/derailed/k9s

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386

USES=		go:1.25+,modules
GO_MODULE=	github.com/derailed/k9s
GO_BUILDFLAGS=	-ldflags="-X github.com/derailed/k9s/cmd.version=${DISTVERSIONFULL} \
		-X github.com/derailed/k9s/cmd.date=$$(date +'%Y-%m-%dT%H:%M:%SZ') \
		-X github.com/derailed/k9s/cmd.commit=6dbf571c59fd48dc5b384aa46ee7f3e5decfae2b"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
