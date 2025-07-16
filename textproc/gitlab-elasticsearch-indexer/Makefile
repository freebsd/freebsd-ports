PORTNAME=	gitlab-elasticsearch-indexer
PORTVERSION=	5.7.0
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

USES=		gmake go:modules,no_targets,1.24 pkgconfig

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
GO_MOD_DIST=	gitlab
GO_MODULE=	gitlab.com/gitlab-org/gitlab-elasticsearch-indexer

MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"
# make sure to pass go build options into make process
MAKE_ENV+=	${GO_ENV}

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
