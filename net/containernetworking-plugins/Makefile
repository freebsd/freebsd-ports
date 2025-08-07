PORTNAME=	containernetworking-plugins
DISTVERSIONPREFIX=	freebsd-v
DISTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	dfr@FreeBSD.org
COMMENT=	Networking plugins for container networking support
WWW=		https://www.cni.dev/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:no_targets
BUILD_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	dfr
GH_PROJECT=	plugins
GH_TUPLE=	golang:sys:v0.6.0:sys

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

do-build:
	cd ${WRKSRC} && ${SETENV} XDG_CACHE_HOME=${WRKDIR}/.cache GO=${GO_CMD} ./build_freebsd.sh

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/cni
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/containers
	cd ${WRKSRC} && ${INSTALL_PROGRAM} bin/* ${STAGEDIR}${PREFIX}/libexec/cni
	${INSTALL_DATA} files/pf.conf.sample ${STAGEDIR}${PREFIX}/etc/containers

.include <bsd.port.mk>
