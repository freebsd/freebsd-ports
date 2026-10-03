PORTNAME=	fjord
DISTVERSION=	0.3.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/daemonless/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	michaeljohnson@ahze.net
COMMENT=	Web UI for managing container compose stacks
WWW=		https://fjord.daemonless.io

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules python:env

GO_TARGET=	./cmd/fjordd:${PREFIX}/sbin/fjordd
GO_LDFLAGS=	-X main.version=${DISTVERSION}

USE_RC_SUBR=	fjordd

OPTIONS_MULTI=	ENGINE
OPTIONS_MULTI_ENGINE=	APPJAIL PODMAN
OPTIONS_DEFAULT=	APPJAIL PODMAN
ENGINE_DESC=	Container engines (at least one)
APPJAIL_DESC=	AppJail engine (appjail, appjail-director)
PODMAN_DESC=	Podman engine (podman, podman-compose)

APPJAIL_RUN_DEPENDS=	appjail>=5.5.0:sysutils/appjail \
		${PYTHON_PKGNAMEPREFIX}director>=0.18.0:sysutils/py-director@${PY_FLAVOR}
PODMAN_RUN_DEPENDS=	podman:sysutils/podman \
		${PYTHON_PKGNAMEPREFIX}podman-compose>=1.2.0:sysutils/podman-compose@${PY_FLAVOR} \
		ocijail>=0.6.0:sysutils/ocijail \
		${LOCALBASE}/libexec/cni/dnsname:sysutils/cni-dnsname \
		${LOCALBASE}/libexec/cni/epair:sysutils/cni-epair

PLIST_FILES=	sbin/fjordd

SUB_FILES=	pkg-message

.include <bsd.port.mk>
