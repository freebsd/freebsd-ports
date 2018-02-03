# $FreeBSD$

PORTNAME=	glucose
DISTVERSION=	4.1
CATEGORIES=	math
MASTER_SITES=	http://www.labri.fr/perso/lsimon/downloads/softwares/
DISTNAME=	glucose-syrup-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parallel SAT solver based on Minisat, with glue clauses

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		gmake tar:tgz

PLIST_FILES=	bin/glucose bin/glucose-syrup

do-build:
	@cd ${WRKSRC}/simp && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}
	@cd ${WRKSRC}/parallel && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/simp/glucose ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/parallel/glucose-syrup ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
