PORTNAME=	k9s
DISTVERSIONPREFIX=	v
DISTVERSION=	0.31.9
CATEGORIES=	sysutils

MAINTAINER=	gogolok@gmail.com
COMMENT=	Kubernetes command-line tool
WWW=		https://github.com/derailed/k9s

LICENSE=	APACHE20

USES=		go:1.21,modules
GO_MODULE=      github.com/derailed/k9s
GO_BUILDFLAGS=	-ldflags="-X github.com/derailed/k9s/cmd.version=${DISTVERSIONFULL} \
		-X github.com/derailed/k9s/cmd.date=$$(date +'%Y-%m-%dT%H:%M:%SZ') \
		-X github.com/derailed/k9s/cmd.commit=f2f4077b592dcbb4162cbfe07bd99546d47d9955"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
