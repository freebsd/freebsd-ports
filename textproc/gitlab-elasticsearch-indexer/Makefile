PORTNAME=	gitlab-elasticsearch-indexer
PORTVERSION=	4.5.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Elasticsearch indexer for GitLab
WWW=		https://gitlab.com/gitlab-org/gitlab-elasticsearch-indexer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	git>=2.38.1:devel/git
LIB_DEPENDS=	libicui18n.so:devel/icu \
		libicuuc.so:devel/icu
#RUN_DEPENDS=	p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool

USES=		gmake go:modules,no_targets pkgconfig

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org

MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"
# make sure to pass go build options into make process
MAKE_ENV+=	${GO_ENV}

# for go dependencies
# Gitlab hosts there dependencies on their own platform and not on go-proxy
# so we download the required go.mod file from gitlab
# lines are taken from go.mk
# ---------------------------
FETCH_DEPENDS=	${GO_CMD}:${GO_PORT}
MASTER_SITES+=	https://gitlab.com/gitlab-org/gitlab-elasticsearch-indexer/-/raw/v${DISTVERSION}/
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

PLIST_FILES=	bin/${PORTNAME}

# add a git tag, as that is required by the build script
pre-build:
	cd ${WRKSRC} && \
		git init && \
		git config user.email "${MAINTAINER}" && \
		git config user.name "Matthias Fechner" && \
		git add . && \
		git commit -m "tag" && \
		git tag v${PORTVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
