PORTNAME=	opa
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.1
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Policy Agent for policy enforcement across the entire stack
WWW=		https://www.openpolicyagent.org/ \
		https://github.com/open-policy-agent/opa

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24+,modules

GO_MODULE=	github.com/open-policy-agent/opa

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
