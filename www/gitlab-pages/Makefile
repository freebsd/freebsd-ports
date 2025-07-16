PORTNAME=	gitlab-pages
PORTVERSION=	${GITLAB_VERSION}
DISTVERSIONPREFIX=	v
PORTREVISION=	${GITLAB_PORTREVISION} # modify it in www/gitlab/Makefile.common
CATEGORIES=	www
MASTER_SITES+=	https://gitlab.com/gitlab-org/gitlab-pages/-/raw/v${DISTVERSION}/
DISTFILES+=	go.mod

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Official GitLab Pages daemon
WWW=		https://gitlab.com/gitlab-org/gitlab-pages

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,1.23

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
USE_RC_SUBR=	gitlab_pages

GO_MODULE=	gitlab.com/gitlab-org/gitlab-pages
GO_BUILDFLAGS=	-ldflags="-X 'main.VERSION=${PORTVERSION}' -X 'main.REVISION=${GL_TAGNAME}'"

USERS=		gitlab-pages
GROUPS=		gitlab-pages

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/gitlab-pages.conf.sample

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	(cd ${WRKDIR}/bin/ && ${COPYTREE_BIN} .  ${STAGEDIR}${DATADIR}/bin)
.for x in gitlab-pages.conf.sample
	${INSTALL_DATA} ${WRKSRC}/${x} ${STAGEDIR}${DATADIR}/
.endfor

post-install:
	${FIND} -s ${STAGEDIR}${DATADIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' | \
		${SED} -E -e '/sample$$/ s#^#@sample #; \
		s#${DATADIR_REL}/bin#@(,,555) ${DATADIR_REL}/bin#; ' >> ${TMPPLIST}
	cat ${TMPPLIST}

.include "${.CURDIR}/../gitlab/Makefile.common"
.include <bsd.port.mk>
