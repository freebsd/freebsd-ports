# New ports collection makefile for:	OpenSSH-askpass
# Version required:	1.2.2
# Date created:		27 February 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	X11/xc/programs/ssh-askpass
PKGNAME=	OpenSSH-askpass-1.2.2
CATEGORIES=	security
# ${MASTER_SITES} is only for if CVS won't work, period.
MASTER_SITES=	http://www.freebsd.org/~kris/distfiles/

MAINTAINER=	kris@FreeBSD.org

USE_IMAKE=	yes

.include <bsd.port.pre.mk>
CAT?=		/bin/cat
SED?=		/usr/bin/sed
DISTFILES!=	${SED} 's:^\(.*\)$$:${PKGNAME}/\1:g' ${FILESDIR}/distfiles
IGNOREFILES!=	${SED} 's:^\(.*\)$$:${PKGNAME}/\1:g' ${FILESDIR}/ignorefiles
DISTFILES+=	${IGNOREFILES}

CVS_CMD?=	cvs -z3
CVS_DATE=	Sun Feb 27 22:21:56 PST 2000
CVS_DATE_!=	${ECHO} -n "${CVS_DATE}" | ${SED} 's/[ \t:]/_/g'
CVS_SITES=	anoncvs@anoncvs1.ca.openbsd.org:/cvs \
		:pserver:anoncvs@anoncvs1.usa.openbsd.org:/cvs
STAMPFILE=	${DISTDIR}/${PKGNAME}/.stamp
WRKSRC=		${WRKDIR}/ssh-askpass

do-fetch:
	@if [ ! -e ${STAMPFILE} ] || \
	    [ "X${CVS_DATE}" != "X$$(${CAT} ${STAMPFILE})" ]; then \
		if [ -e ${DISTDIR}/${PKGNAME}.${CVS_DATE_}.tar.gz ]; then \
			cd ${DISTDIR}; \
			${TAR} xfz ${PKGNAME}.${CVS_DATE_}.tar.gz \
			    ${DISTFILES}; \
			${ECHO} -n "${CVS_DATE}" > ${STAMPFILE}; \
			exit; \
		fi; \
		unset CVS_RSH CVS_SERVER || ${TRUE}; \
		if [ -n "${PORTS_CVS_RSH}" ]; then \
			export CVS_RSH="${PORTS_CVS_RSH}"; \
		fi; \
		${MKDIR} ${DISTDIR}/${PKGNAME} && \
		cd ${DISTDIR}/${PKGNAME}; \
		for CVS_SITE in ${CVS_SITES}; do \
			${ECHO_MSG} ">> Attempting to CVS checkout from $${CVS_SITE}."; \
			if ${CVS_CMD} -d $${CVS_SITE} co -D "${CVS_DATE}" \
			    ${DISTNAME}; then \
				${ECHO} -n "${CVS_DATE}" > ${STAMPFILE}; \
				exit; \
			fi \
		done; \
		${ECHO_MSG} ">> Couldn't CVS checkout ${PKGNAME}.  Please try to retrieve"; \
		${ECHO_MSG} ">> a snapshot with \"make fetchsrctarball\" and try again."; \
		exit 1; \
	fi

makesrctarball: fetch
	@cd ${DISTDIR}; \
	${ECHO_MSG} ">> Creating source tarball in ${DISTDIR}"; \
	${ECHO_MSG} ">> \"${PKGNAME}.${CVS_DATE_}.tar.gz\"."; \
	${TAR} cfz ${PKGNAME}.${CVS_DATE_}.tar.gz ${PKGNAME}

fetchsrctarball:
	@cd ${DISTDIR}; \
	file=${PKGNAME}.${CVS_DATE_}.tar.gz; \
	if [ -e $$file ]; then \
		exit; \
	fi; \
	${ECHO_MSG} ">> $$file doesn't seem to exist on this system."; \
	for site in ${MASTER_SITES}; do \
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

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} -r ${DISTDIR}/${PKGNAME}/${DISTNAME} ${WRKDIR}

pre-install:
	${MKDIR} ${PREFIX}/share/doc/ssh-askpass
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ssh-askpass/

.include <bsd.port.post.mk>
