# New ports collection makefile for:	mozilla-embedded
# Date created:				16 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mozilla-embedded
PORTVERSION=	${MAKE} -V PORTVERSION -f ${MAINDIR}/${MKFILE}
PORTREVISION=	${MAKE} -V PORTREVISION -f ${MAINDIR}/${MKFILE}
PORTEPOCH=	${MAKE} -V PORTEPOCH -f ${MAINDIR}/${MKFILE}
CATEGORIES=	www
DISTFILES=

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/www/mozilla-devel:build \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	${MAKE} -V LIB_DEPENDS -f ${MAINDIR}/${MKFILE}
RUN_DEPENDS=	${MAKE} -V RUN_DEPENDS -f ${MAINDIR}/${MKFILE}

USE_X_PREFIX=	yes

NO_LATEST_LINK=	yes

MAINDIR=	${.CURDIR}/../mozilla-devel
MKFILE!=	/usr/bin/basename ${MAKEFILE}
PORTVERSION!=	${PORTVERSION}
PORTREVISION!=	${PORTREVISION}
PORTEPOCH!=	${PORTEPOCH}
RUN_DEPENDS!=	${RUN_DEPENDS}
LIB_DEPENDS!=	${LIB_DEPENDS}
WRKSRC=		${WRKDIRPREFIX}${MAINDIR}/work/mozilla

do-build:
	@cd ${WRKSRC}/embedding/config && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
	@(cd ${WRKSRC}/dist/Embed; \
	  ${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ../bin/regxpcom; \
	  ${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ../bin/regchrome)
	@find ${WRKSRC}/dist/Embed -name "*.so" | xargs strip

do-install:
	${MKDIR} ${PREFIX}/lib/mozilla-embedded-devel
	${CHMOD} 755 ${PREFIX}/lib/mozilla-embedded-devel
	cd ${WRKSRC}/dist/Embed && ${FIND} . | \
		cpio -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/mozilla-embedded-devel

.include <bsd.port.mk>
