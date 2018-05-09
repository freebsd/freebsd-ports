# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-workhorse
PORTVERSION=	4.0.0
CATEGORIES=	www

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go>=1.5.3:lang/go

MAKE_JOBS_UNSAFE=yes
USES=	gmake
USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find the commit hash here: https://gitlab.com/gitlab-org/gitlab-workhorse/tags
GL_COMMIT=	75bc61a1ac262705a24e38c3fc6b388efb0fb5c4

PLIST_FILES=	bin/gitlab-workhorse \
		bin/gitlab-zip-cat \
		bin/gitlab-zip-metadata
PLIST_DIRS=	${WWWDIR}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gitlab-workhorse
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gitlab-zip-cat
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gitlab-zip-metadata

.include <bsd.port.mk>
