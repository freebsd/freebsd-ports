# New ports collection makefile for: lib
# Date Created:		19 September 2000
# Whom:			nra
#
# $FreeBSD$
#

PORTNAME=	libh
PORTVERSION=	0.2.2
CATEGORIES=	misc
# ${MASTER_SITES} is unavailable for CVS only projects.
# MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	anarcat@anarcat.dyndns.org

LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83 \
		tvision.0:${PORTSDIR}/devel/tvision
BUILD_DEPENDS= 	${X11BASE}/lib/libqt2.a:${PORTSDIR}/x11-toolkits/qt2-static

USE_QT_VER=	2
IS_INTERACTIVE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

# we could also use the makedistfiles method here
DISTFILES!=	${CAT} ${FILESDIR}/distfiles

CVS_CMD?=	cvs -z3
# use the newly introduced release tag
CVS_TAG=	r0_2_2
CVS_SITES?=	:pserver:anonymous@usw4.freebsd.org:/home/libh/cvs
STAMPFILE=	${DISTDIR}/${DISTNAME}/.stamp

WRKSRC=		${WRKDIR}/${PORTNAME}

# until we find a way of including ${WRKSRC}/${PORTNAME}/Makefile.uitype
# only after "extract"
UITYPE=		text+graphics

.if defined(BATCH)
do-fetch: fetchsrctarball
.else
do-fetch:
	@if [ ! -f ${STAMPFILE} ] || \
		[ "X${CVS_TAG}" != "X$$(${CAT} ${STAMPFILE})" ]; then \
		${ECHO_MSG} "No stamp file (or out of date)"; \
		if [ -f ${DISTDIR}/${DISTNAME}.tar.gz ]; then \
			cd ${DISTDIR}; \
			${TAR} xfz ${DISTNAME}.tar.gz \
				${DISTFILES}; \
			${ECHO_CMD} -n "${CVS_TAG}" > ${STAMPFILE}; \
			exit; \
		fi; \
		unset CVS_RSH CVS_SERVER CVS_LOGIN || ${TRUE}; \
		if [ -n "${PORTS_CVS_RSH}" ]; then \
			export CVS_RSH="${PORTS_CVS_RSH}"; \
		fi; \
		if [ -n "${PORTS_CVS_SERVER}" ]; then \
			export CVS_SERVER="${PORTS_CVS_SERVER}"; \
		fi; \
		export CVS_PASSFILE="${FILESDIR}/cvspass"; \
		${MKDIR} ${DISTDIR}/${PKGNAME} && \
		cd ${DISTDIR}/${PKGNAME}; \
		for CVS_SITE in ${CVS_SITES}; do \
			${ECHO_MSG} ">> Attempting to CVS cvs checkout from $${CVS_SITE}."; \
			if ${CVS_CMD} -d $${CVS_SITE} co -r '${CVS_TAG}' ${PORTNAME}; then \
				if [ "X$${CVS_LOGIN}" = "Xyes" ]; then \
					${CVS_CMD} -d $${CVS_SITE} logout < /dev/null; \
				fi; \
				${ECHO_CMD} -n ${CVS_TAG} > ${STAMPFILE}; \
				${ECHO_MSG} ">> CVS checkout successful." ;\
				exit; \
			fi ;\
		done; \
		${ECHO_MSG} ">> Couldn't CVS checkout ${PORTNAME}." ;\
		exit 1; \
	fi
.endif

makesrctarball:	fetch
	@cd ${DISTDIR}; \
	${ECHO_MSG} ">> Creating source tarball in ${DISTDIR}"; \
	${ECHO_MSG} ">> \"${DISTNAME}.tar.gz\"."; \
	${TAR} cfz ${DISTNAME}.tar.gz ${DISTNAME}

fetchsrctarball:
	@cd ${DISTDIR}; \
	file=${DISTNAME}.tar.gz; \
	if [ -e $$file ]; then \
		exit; \
	fi; \
	${ECHO_MSG} ">> $$file doesn't seem to exist on this system."; \
	for site in ${MASTER_SITES};  do \
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

makedistfiles: fetch
	cd ${DISTDIR} && find ${DISTNAME} \! -type d | \
		egrep -v CVS\|.stamp > ${FILESDIR}/distfiles

do-extract:
	@${MKDIR} ${WRKDIR}
	@(cd ${DISTDIR}/${DISTNAME}/${PORTNAME} && \
		find . ! -path *CVS* -print | \
		cpio -pdmu ${WRKSRC} > /dev/null 2>&1)

do-build:
	(cd ${BUILD_WRKSRC}; ${MAKE} ${MAKE_ARGS} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

.include <bsd.port.post.mk>
