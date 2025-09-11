PORTNAME=	podman-suite
PORTVERSION=	20250905
CATEGORIES=	sysutils

MAINTAINER=	dfr@FreeBSD.org
COMMENT=	Metaport of Podman and Buildah toolkit
WWW=		https://podman.io/

USES=		metaport

RUN_DEPENDS=	buildah>=0:sysutils/buildah \
		catatonit>=0:sysutils/catatonit \
		podman>=0:sysutils/podman \
		skopeo>=0:sysutils/skopeo

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		not supported for this configuration
.endif

.include <bsd.port.mk>
