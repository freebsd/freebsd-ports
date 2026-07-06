PORTNAME=	gitlab-registry
PORTVERSION=	4.40.2
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-gitlab
CATEGORIES=	sysutils

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	GitLab Container Registry fork with optimized metadata handling
WWW=		https://gitlab.com/gitlab-org/container-registry

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules,no_targets

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
GL_PROJECT=	container-registry

GO_MOD_DIST=	gitlab
GO_MODULE=	github.com/docker/distribution
#GO_BUILDFLAGS=	-buildmode=pie

SUB_FILES=	pkg-message

USE_RC_SUBR=	gitlab_registry

USERS=		git
GROUPS=		git

PLIST_FILES=	bin/registry \
		"@sample ${ETCDIR}/config.yml.sample" \
		"${ETCDIR}/filesystem.yml.sample" \
		"${ETCDIR}/database-filesystem.yml.sample"

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/config/filesystem.yml

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/registry ${STAGEDIR}${PREFIX}/bin

	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/filesystem.yml ${STAGEDIR}${PREFIX}/etc/gitlab-registry/config.yml.sample
	${INSTALL_DATA} ${WRKSRC}/config/filesystem.yml ${STAGEDIR}${PREFIX}/etc/gitlab-registry/filesystem.yml.sample
	${INSTALL_DATA} ${WRKSRC}/config/database-filesystem.yml ${STAGEDIR}${PREFIX}/etc/gitlab-registry/database-filesystem.yml.sample

.include <bsd.port.mk>
