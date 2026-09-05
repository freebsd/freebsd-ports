PORTNAME=	cni-dnsname
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
CATEGORIES=	sysutils

MAINTAINER=	adrian@FreeBSD.org
COMMENT=	DNS name resolution for containers (CNI plugin)
WWW=		https://github.com/containers/dnsname

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dnsmasq:dns/dnsmasq

USES=		go:modules
GO_MODULE=	github.com/containers/dnsname
GO_TARGET=	./plugins/meta/dnsname

PLIST_FILES=	libexec/cni/dnsname

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/cni
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/dnsname ${STAGEDIR}${PREFIX}/libexec/cni

.include <bsd.port.mk>
