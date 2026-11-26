PORTNAME=	paseo-web
.include "${.CURDIR}/../../misc/paseo/Makefile.common"
CATEGORIES=	www
MASTER_SITES=	https://registry.npmjs.org/@getpaseo/server/-/
DISTNAME=	server-${DISTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Agentic development environment (web app)
WWW=		https://paseo.sh/ \
		https://github.com/getpaseo/paseo

LICENSE=	APACHE20
LICENSE_FILE=	${WRKDIR}/package/LICENSE

USES=		tar:tgz

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

# Take only the prebuilt web app from the daemon's npm package.
EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions \
		package/LICENSE package/${WRKSRC_SUBDIR}
WRKSRC=		${WRKDIR}/package
WRKSRC_SUBDIR=	dist/server/web-ui

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} -s ${WWWDIR_REL} -not -type d >> ${TMPPLIST}

.include <bsd.port.mk>
