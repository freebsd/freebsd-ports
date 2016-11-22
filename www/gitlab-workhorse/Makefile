# Created by: Torsten Zuehlsdorff <ports@toco-domains.de
# $FreeBSD$

PORTNAME=	gitlab-workhorse
PORTVERSION=	0.7.11
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	https://gitlab.com/gitlab-org/${PORTNAME}/repository/archive.tar.gz?ref=${DISTVERSIONPREFIX}${PORTVERSION}&dummy=/

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go>=1.5.3:lang/go

MAKE_JOBS_UNSAFE=yes
USES=	gmake

PLIST_FILES=	bin/gitlab-workhorse \
		bin/gitlab-zip-cat \
		bin/gitlab-zip-metadata
PLIST_DIRS=	%%WWWDIR%%

post-extract:
	@${MV} ${WRKDIR}/${DISTNAME}-* ${WRKDIR}/${DISTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gitlab-workhorse
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gitlab-zip-cat
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gitlab-zip-metadata

.include <bsd.port.mk>
