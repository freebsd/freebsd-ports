PORTNAME=	glucose
DISTVERSION=	4.2.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parallel SAT solver based on Minisat, with glue clauses
WWW=		https://www.labri.fr/perso/lsimon/glucose/ \
		https://github.com/audemard/glucose

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gmake

USE_GITHUB=	yes
GH_ACCOUNT=	audemard

PLIST_FILES=	bin/glucose bin/glucose-syrup

do-build:
	@cd ${WRKSRC}/simp && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}
	@cd ${WRKSRC}/parallel && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/simp/glucose ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/parallel/glucose-syrup ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
