PORTNAME=	gitlab-pages
PORTVERSION=	16.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES+=	https://gitlab.com/gitlab-org/gitlab-pages/-/raw/v${DISTVERSION}/
DISTFILES+=	go.mod

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Official GitLab Pages daemon
WWW=		https://gitlab.com/gitlab-org/gitlab-pages

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	gitlab.com/gitlab-org/gitlab-pages

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find this here: https://gitlab.com/gitlab-org/gitlab-pages/-/tags/
GL_COMMIT=	2c45328a9823673f57dde87737c2f317e594e172

GO_BUILDFLAGS=	-ldflags="-X 'main.VERSION=${PORTVERSION}' -X 'main.REVISION=${GL_COMMIT}'"

PLIST_FILES=	bin/gitlab-pages

USE_RC_SUBR=	gitlab_pages

USERS=		gitlab-pages
GROUPS=		gitlab-pages

.include <bsd.port.mk>
