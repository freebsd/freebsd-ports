# New ports collection makefile for:	mozilla-embedded
# Date created:				16 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mozilla-embedded
PORTVERSION=	${MAKE} -V PORTVERSION -f ${MAINDIR}/${MAKEFILE}
PORTREVISION=	${MAKE} -V PORTREVISION -f ${MAINDIR}/${MAKEFILE}
PORTEPOCH=	${MAKE} -V PORTEPOCH -f ${MAINDIR}/${MAKEFILE}
CATEGORIES=	www
DISTFILES=

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/www/mozilla:build \
		zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	${MAKE} -V LIB_DEPENDS -f ${MAINDIR}/${MAKEFILE}
RUN_DEPENDS=	${MAKE} -V RUN_DEPENDS -f ${MAINDIR}/${MAKEFILE}

USE_X_PREFIX=	yes

MAINDIR=	${.CURDIR}/../mozilla
PORTVERSION!=	${PORTVERSION}
PORTREVISION!=	${PORTREVISION}
PORTEPOCH!=	${PORTEPOCH}
RUN_DEPENDS!=	${RUN_DEPENDS}
LIB_DEPENDS!=	${LIB_DEPENDS}
WRKSRC=		${WRKDIRPREFIX}${MAINDIR}/work/mozilla

do-build:
	${PERL} -pi -e 's|\\|/|g' ${WRKSRC}/embedding/config/Makefile
	cd ${WRKSRC}/embedding/config && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
	(cd ${WRKSRC}/dist/bin && \
	  ${SETENV} LD_LIBRARY_PATH=${WRKSRC}/dist/Embed \
		MOZILLA_FIVE_HOME=${WRKSRC}/dist/Embed ./regxpcom)
	find ${WRKSRC}/dist/Embed -name "*.so" | xargs strip

do-install:
	${MKDIR} ${PREFIX}/lib/mozilla-embedded
	${CHMOD} 755 ${PREFIX}/lib/mozilla-embedded
	cd ${WRKSRC}/dist/Embed && ${TAR} -chf - * | \
		${TAR} -xf - -C ${PREFIX}/lib/mozilla-embedded

.include <bsd.port.mk>
