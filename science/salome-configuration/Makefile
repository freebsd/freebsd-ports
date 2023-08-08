PORTNAME=	salome-configuration
DISTVERSIONPREFIX=	V
DISTVERSION=	9_11_0
CATEGORIES=	science # physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Salome Project: Multi-physics simulations: Configuration
WWW=		https://www.salome-platform.org/

FETCH_DEPENDS=	git:devel/git

GIT_URL=	https://git.salome-platform.org/gitpub/tools/configuration.git # all Salome repositories: https://git.salome-platform.org/gitweb/

DATADIR=	${PREFIX}/share/salome

NO_BUILD=	yes
NO_ARCH=	yes

do-fetch:
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}" ]; then \
	  ${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
	  cd ${DISTDIR}/${DIST_SUBDIR} && \
	    git clone -q ${GIT_URL} ${PORTNAME}-${DISTVERSIONFULL} && \
	    (cd ${PORTNAME}-${DISTVERSIONFULL} && git reset -q --hard ${DISTVERSIONFULL} && ${RM} -r .git) && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -print0 | LC_ALL=C ${SORT} -z | \
	        ${TAR} czf ${PORTNAME}-${DISTVERSIONFULL}${EXTRACT_SUFX} --format=bsdtar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T - && \
	    ${RM} -r ${PORTNAME}-${DISTVERSIONFULL}; \
	fi

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/configuration
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/configuration
	${RM} ${STAGEDIR}${DATADIR}/configuration/.gitignore

.include <bsd.port.mk>
