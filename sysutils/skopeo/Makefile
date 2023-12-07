PORTNAME=	skopeo
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.3
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	dfr@FreeBSD.org
COMMENT=	Inspect container images and repositories on registries
WWW=		https://github.com/containers

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash \
		curl:ftp/curl \
		go-md2man:textproc/go-md2man
LIB_DEPENDS=	libgpgme.so:security/gpgme
RUN_DEPENDS=	${LOCALBASE}/etc/containers/containers.conf.sample:sysutils/containers-common

USES=		gmake go:modules,no_targets pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	containers
GH_PROJECT=	skopeo

do-install:
	${SETENV} ${MAKE_ENV} ${GO_ENV} ${GMAKE} -C ${WRKSRC} \
		DESTDIR=${STAGEDIR} GOCACHE=${TMPDIR} \
		GO=${GO_CMD} install-binary install-docs install-completions
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/containers/registries.d
	${INSTALL_DATA} ${WRKSRC}/default.yaml ${STAGEDIR}${PREFIX}/etc/containers/registries.d/default.yaml

.include <bsd.port.mk>
