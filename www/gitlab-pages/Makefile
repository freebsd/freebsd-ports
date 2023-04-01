PORTNAME=	gitlab-pages
PORTVERSION=	15.8.5
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES+=	https://gitlab.com/gitlab-org/gitlab-pages/-/raw/v${DISTVERSION}/
DISTFILES+=	go.mod

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Official GitLab Pages daemon
WWW=		https://gitlab.com/gitlab-org/gitlab-pages

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	gitlab.com/gitlab-org/gitlab-pages

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find this here: https://gitlab.com/gitlab-org/gitlab-pages/-/tags/
GL_COMMIT=	60b1bdb27c50c564cf9eeb00b2a5c9fb818542b1

GO_BUILDFLAGS=	-ldflags="-X 'main.VERSION=${PORTVERSION}' -X 'main.REVISION=${GL_COMMIT}'"

PLIST_FILES=	bin/gitlab-pages

USE_RC_SUBR=	gitlab_pages

USERS=		gitlab-pages
GROUPS=		gitlab-pages

.include <bsd.port.mk>
