# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-workhorse
PORTVERSION=	8.3.1
CATEGORIES=	www

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go>=1.8.0:lang/go \
		git>=2.16.2:devel/git

MAKE_JOBS_UNSAFE=yes
USES=	gmake
USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find the commit hash here: https://gitlab.com/gitlab-org/gitlab-workhorse/tags
GL_COMMIT=	96dea75b2b9a13d1cfa77702b54113ffc388eae3

PLIST_FILES=	bin/gitlab-workhorse \
		bin/gitlab-zip-cat \
		bin/gitlab-zip-metadata
PLIST_DIRS=	${WWWDIR}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}

.include <bsd.port.mk>
