# New ports collection makefile for: lgrind
# Date created:				20 April 2002
# Whom:					Kay Lehmann
#
# $FreeBSD$
#

PORTNAME=	lgrind
PORTVERSION=	3.67
PORTREVISION=	5
CATEGORIES=	print
MASTER_SITES=	LOCAL/pav

DISTNAME=	${PORTNAME}
DISTFILES=	source/Makefile \
		source/README \
		FAQ \
		README \
		Makefile \
		example/asm2tex.bat \
		example/asm2tex \
		example/c2tex.bat \
		example/c2tex \
		example/lgrindeg.tex \
		example/egcprog.c \
		example/egmasm.asm \
		example/subst \
		lgrind.dtx \
		lgrind.gls \
		lgrind.ind \
		lgrind.ins \
		lgrind.pdf \
		lgrindef \
		source/.cvsignore \
		source/lgrind.1 \
		source/lgrind.c \
		source/lgrindef.5 \
		source/lgrindef.c \
		source/lgrindef.h \
		source/lgutil.c \
		source/makefile.dos \
		source/makefile.emx \
		source/regexp.c \
		source/regexp.h \
		source/retest.c \
		source/v2lg.c \
		${PORTNAME}.tar.gz

DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}.tar.gz

MAINTAINER=	dereckson@gmail.com
COMMENT=	Produce beautiful listings of source code with LaTeX

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

MAN1=		lgrind.1
MAN5=		lgrindef.5
MANCOMPRESSED=	yes

IGNOREFILES=	${PORTNAME}.tar.gz

RESTRICTED=	According to the README-file there is a license issue \
		because of non-free code. Check the README file within \
		the source tarball. No response from author of some code \
		this port is based on.

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
	${GUNZIP_CMD} -qc ${DISTDIR}/${DIST_SUBDIR}/${EXTRACT_ONLY} | tar -C ${DISTDIR} -xf -; \
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
