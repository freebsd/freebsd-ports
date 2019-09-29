# $FreeBSD$

PORTNAME=	gitlab-pages
PORTVERSION=	1.7.2
CATEGORIES=	www

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Official GitLab Pages daemon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find the here: https://gitlab.com/gitlab-org/gitlab-pages/tags
GL_COMMIT=	520398c7154a50f7768ee52da71afd52efff85b1

GO_BUILDFLAGS=	-ldflags="-X main.VERSION=${PORTVERSION} -X main.REVISION=${GITHASH}"
GO_PKGNAME=	gitlab.com/gitlab-org/gitlab-pages

PLIST_FILES=	bin/gitlab-pages

USE_RC_SUBR=	gitlab_pages

USERS=		gitlab-pages
GROUPS=		gitlab-pages

.include <bsd.port.mk>
