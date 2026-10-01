PORTNAME=	opa
DISTVERSIONPREFIX=	v
DISTVERSION=	1.21.0
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Policy Agent for policy enforcement across the entire stack
WWW=		https://www.openpolicyagent.org/ \
		https://github.com/open-policy-agent/opa

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/open-policy-agent/opa
# Test expects a Go runtime metric that is not present in this Go version/build
GO_TESTFLAGS+=	-skip TestJSONSerialization

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
