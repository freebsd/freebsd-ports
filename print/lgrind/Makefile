# New ports collection makefile for: lgrind
# Date created:				20 April 2002
# Whom:					Kay Lehmann
#
# $FreeBSD$
#

PORTNAME=	lgrind
PORTVERSION=	3.67
PORTREVISION=	1
CATEGORIES=	print
#MASTER_SITES=	ftp://ftp.dante.de/tex-archive/support/ \
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=support
DISTNAME=	${PORTNAME}
DISTFILES=	${PORTNAME}/source/Makefile \
		${PORTNAME}/source/README \
		${PORTNAME}/FAQ \
		${PORTNAME}/README \
		${PORTNAME}/Makefile \
		${PORTNAME}/lgrind.dtx \
		${PORTNAME}/lgrind.dtx \
		${PORTNAME}/lgrind.gls \
		${PORTNAME}/lgrind.ind \
		${PORTNAME}/lgrind.ins \
		${PORTNAME}/lgrindef \
		${PORTNAME}/source/lgrind.1 \
		${PORTNAME}/source/lgrind.c \
		${PORTNAME}/source/lgrindef.5 \
		${PORTNAME}/source/lgrindef.c \
		${PORTNAME}/source/lgrindef.h \
		${PORTNAME}/source/lgutil.c \
		${PORTNAME}/source/regexp.c \
		${PORTNAME}/source/regexp.h \
		${PORTNAME}/source/retest.c \
		${PORTNAME}/source/v2lg.c
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}.tar.gz

MAINTAINER=	kay_lehmann@web.de
COMMENT=	Produce beautiful listings of source code with LaTeX

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

USE_REINPLACE=	yes

MAN1=		lgrind.1
MAN5=		lgrindef.5
MANCOMPRESSED=	yes

IGNOREFILES=	${PORTNAME}.tar.gz

NO_CDROM=	"According to the README-file there is a license issue because of non-free code. Check the README file within the source tarball."
NO_PACKAGE=	"According to the README-file there is a license issue because of non-free code. Check the README file within the source tarball."
RESTRICTED=	"No response from author of some code this port is based on"

pre-everything::
	@${MKDIR} ${DISTDIR}/${PORTNAME}

pre-fetch:	fetchsrctarball extractsrctarball

fetchtarball-list:
	file=${PORTNAME}${EXTRACT_SUFX}; \
	for site in ${MASTER_SITES:S^%SUBDIR%^${MASTER_SITE_SUBDIR}^}; do \
		${ECHO_MSG} ">>${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${site}$${file} not fetched"; \
	done;

fetchsrctarball:
	@cd ${_DISTDIR}; \
	file=${PORTNAME}${EXTRACT_SUFX}; \
	if [ -e $$file ]; then \
		exit; \
	fi; \
	${ECHO_MSG} ">> $$file doesn't seem to exist on this system."; \
	for site in ${MASTER_SITES:S^%SUBDIR%^${MASTER_SITE_SUBDIR}^}; do \
		${ECHO_MSG} ">> Attempting to fetch from $${site}."; \
		if ${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS} \
		    $${site}$${file}; then \
			exit; \
		fi; \
	done; \
	${ECHO_MSG} ">> Couldn't fetch $$file."; \
	${ECHO_MSG} ">> Please try to retrieve this file manually into"; \
	${ECHO_MSG} ">> ${_DISTDIR} and try again."; \
	exit 1

extractsrctarball:
	${GUNZIP_CMD} -qc ${DISTDIR}/${DIST_SUBDIR}/${IGNOREFILES} | tar -C ${DISTDIR}/${DIST_SUBDIR} -xf -; \
	exit

post-patch:
# PREFIX safeness
	@${REINPLACE_CMD} -E \
		-e s'|^(BASEDIR).*$$|\1=${PREFIX}|' \
		${WRKSRC}/Makefile
# C{C,FLAGS} safeness
	@${REINPLACE_CMD} -E \
		-e s'|^(CC).*$$|\1=${CC}|' \
		-e s'|^(CFLAGS).*$$|\1=${CFLAGS}|' \
		${WRKSRC}/source/Makefile

post-install:
	texhash

.include <bsd.port.mk>
