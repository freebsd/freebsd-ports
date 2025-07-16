PORTNAME=	gitlab-workhorse
PORTVERSION=	${GITLAB_VERSION}
DISTVERSIONPREFIX=	v
PORTREVISION=	${GITLAB_PORTREVISION} # modify it in www/gitlab/Makefile.common
CATEGORIES=	www

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab
WWW=		https://gitlab.com/gitlab-org/gitlab/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	git>=2.42.0:devel/git
RUN_DEPENDS=	p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool

USES=		gmake go:modules,no_targets,1.23
USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
GL_PROJECT=	gitlab-foss
GO_MOD_DIST=	gitlab
GO_MODULE=	gitlab.com/gitlab-org/gitlab/workhorse
MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"
MAKE_ENV+=	${GO_ENV}
WRKSRC_SUBDIR=	workhorse
# found in work/gitlab-foss*/workhorse/go.mod

PLIST_FILES=	bin/gitlab-resize-image \
		bin/gitlab-workhorse \
		bin/gitlab-zip-cat \
		bin/gitlab-zip-metadata

.include "${.CURDIR}/../gitlab/Makefile.common"
.include <bsd.port.mk>
