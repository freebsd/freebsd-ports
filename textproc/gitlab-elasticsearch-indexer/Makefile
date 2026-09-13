PORTNAME=	gitlab-elasticsearch-indexer
PORTVERSION=	5.14.13
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Elasticsearch indexer for GitLab
WWW=		https://gitlab.com/gitlab-org/gitlab-elasticsearch-indexer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	git>=2.38.1:devel/git \
		gitlab-code-parser>=0.22.0:textproc/gitlab-code-parser
LIB_DEPENDS=	libicui18n.so:devel/icu \
		libicuuc.so:devel/icu \
		libparser_c_bindings.so:textproc/gitlab-code-parser
#RUN_DEPENDS=	p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool

NO_SHLIB_REQUIRES_GLOB=	libparser_c_bindings.so

USES=		gmake go:modules,no_targets pkgconfig

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
GO_MOD_DIST=	gitlab
GO_MODULE=	gitlab.com/gitlab-org/gitlab-elasticsearch-indexer

MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"
# make sure to pass go build options into make process
MAKE_ENV+=	${GO_ENV}

PLIST_FILES=	bin/${PORTNAME}

# Since 5.14.13 the go/icu dependency is vendored via a local path replace
# (third_party/icu). The framework's go-post-fetch hook runs "go mod download
# all" from the distdir, where only the bare go.mod has been fetched, and
# resolves that local path relative to it. Extract the subtree from the main
# tarball first (this runs before go-post-fetch).
post-fetch:
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && \
		${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.tar.bz2 \
		--strip-components 1 --no-same-owner --no-same-permissions \
		${DISTNAME}/third_party/icu

post-patch:
	${REINPLACE_CMD} -e '/libparser-download/d' ${WRKSRC}/Makefile

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
