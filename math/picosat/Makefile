# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	picosat
DISTVERSION=	965
CATEGORIES=	math
MASTER_SITES=	http://fmv.jku.at/picosat/

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Satisfiability (SAT) solver for boolean variables

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DEBUG

DEBUG_CONFIGURE_ON=	--debug --log

USE_LDCONFIG=	yes

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--shared --static
CONFIGURE_SCRIPT=	configure.sh

MAKEFILE=		makefile
MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picosat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/picomcs ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/picomus ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/picogcnf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libpicosat.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libpicosat.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/picosat.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
