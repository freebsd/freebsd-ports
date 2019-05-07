# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-workhorse
PORTVERSION=	8.5.2
CATEGORIES=	www

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go>=1.8.0:lang/go \
		git>=2.16.2:devel/git
RUN_DEPENDS=	p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool

USES=	gmake
USE_GITLAB=	yes

GL_ACCOUNT=	gitlab-org
# Find the commit hash here: https://gitlab.com/gitlab-org/gitlab-workhorse/tags
GL_COMMIT=	2419009d10dfff694710cf81fd56bd837269f055
MAKE_JOBS_UNSAFE=yes

PLIST_FILES=	bin/gitlab-workhorse \
		bin/gitlab-zip-cat \
		bin/gitlab-zip-metadata
PLIST_DIRS=	${WWWDIR}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}

.include <bsd.port.mk>
