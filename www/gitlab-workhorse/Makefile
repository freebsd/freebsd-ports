# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>

PORTNAME=	gitlab-workhorse
PORTVERSION=	15.1.2
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	www

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	git>=2.16.2:devel/git
RUN_DEPENDS=	p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool

USES=		gmake go:modules,no_targets
MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"
MAKE_ENV+=	${GO_ENV}
WRKSRC_SUBDIR=	workhorse
# found in work/gitlab-foss*/workhorse/go.mod
#GO_MODULE=	gitlab.com/gitlab-org/gitlab/workhorse

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
GL_PROJECT=	gitlab-foss
# Find the commit hash here: https://gitlab.com/gitlab-org/gitlab-foss/-/tags
GL_COMMIT=	ea7455c82929d4b8e8a81999b0282c3c650ccb9a

# for go dependencies
# Gitlab hosts there dependencies on their own platform and not on go-proxy
# so we download the required go.mod file from gitlab
# lines are taken from go.mk
# ---------------------------
FETCH_DEPENDS=	${GO_CMD}:${GO_PORT} \
		ca_root_nss>0:security/ca_root_nss
MASTER_SITES+=	https://gitlab.com/gitlab-org/gitlab-foss/-/raw/v${DISTVERSION}/workhorse/
DISTFILES+=	go.mod
DIST_SUBDIR=	go/${PKGORIGIN:S,/,_,g}/${DISTNAME}
EXTRACT_ONLY+=	${DISTFILES:N*.mod\:*:N*.mod:C/:.*//}
_USES_fetch+=	800:go-post-fetch
go-post-fetch:
	@${ECHO_MSG} "===> Fetching ${GO_MODNAME} dependencies";
	@(cd ${DISTDIR}/${DIST_SUBDIR}; \
		[ -e go.mod ] || ${RLN} ${GO_MODFILE} go.mod; \
		${SETENV} ${GO_ENV} GOPROXY=${GO_GOPROXY} ${GO_CMD} mod download -x all)
# ---------------------------

PLIST_FILES=	bin/gitlab-resize-image \
		bin/gitlab-workhorse \
		bin/gitlab-zip-cat \
		bin/gitlab-zip-metadata
PLIST_DIRS=	${WWWDIR}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}

.include <bsd.port.mk>
