# New ports collection makefile for: lib
# Date Created:		19 September 2000
# Whom:			nra
#
# $FreeBSD$
#

PORTNAME=	libh
PORTVERSION=	0.2.1
CATEGORIES=	misc
# ${MASTER_SITES} is unavailable for CVS only projects.
# MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	nra@FreeBSD.org

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
# arbitrary date for now.
CVS_DATE=	Thu December 21 18:20:00 GMT 2001
CVS_DATE_!=	${ECHO} -n "${CVS_DATE}" | ${SED} 's/[ \t:]/_/g'
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
		[ "X${CVS_DATE}" != "X$$(${CAT} ${STAMPFILE})" ]; then \
		${ECHO_MSG} "No stamp file (or out of date)"; \
		if [ -f ${DISTDIR}/${DISTNAME}.${CVS_DATE_}.tar.gz ]; then \
			cd ${DISTDIR}; \
			${TAR} xfz ${DISTNAME}.${CVS_DATE_}.tar.gz \
				${DISTFILES}; \
			${ECHO} -n "${CVS_DATE}" > ${STAMPFILE}; \
			exit; \
		fi; \
		unset CVS_RSH CVS_SERVER CVS_LOGIN || ${TRUE}; \
		if [ -n "${PORTS_CVS_RSH}" ]; then \
			export CVS_RSH="${PORTS_CVS_RSH}"; \
		fi; \
		if [ -n "${PORTS_CVS_SERVER}" ]; then \
			export CVS_SERVER="${PORTS_CVS_SERVER}"; \
		fi; \
		${MKDIR} ${DISTDIR}/${PKGNAME} && \
		cd ${DISTDIR}/${PKGNAME}; \
		for CVS_SITE in ${CVS_SITES}; do \
			${ECHO_MSG} ">> Attempting to CVS cvs checkout from $${CVS_SITE}."; \
			case "$${CVS_SITE}" in \
			:pserver:*) \
				CVS_LOGIN=yes; \
				;; \
			*) \
				CVS_LOGIN=no; \
				;; \
			esac; \
			if [ "X$${CVS_LOGIN}" = "Xyes" ]; then \
				${ECHO_MSG} ">> *** Please hit enter here for the password."; \
				${CVS_CMD} -d $${CVS_SITE} login < /dev/null; \
			fi ; \
			if ${CVS_CMD} -d $${CVS_SITE} co -D '${CVS_DATE}' ${PORTNAME}; then \
				if [ "X$${CVS_LOGIN}" = "Xyes" ]; then \
					${CVS_CMD} -d $${CVS_SITE} logout < /dev/null; \
				fi; \
				${ECHO} -n ${CVS_DATE} > ${STAMPFILE}; \
				${ECHO_MSG} ">> CVS checkout successful." ;\
				exit; \
			fi ;\
			if [ "X$${CVS_LOGIN}" = "Xyes" ]; then \
				${CVS_CMD} -d $${CVS_SITE} logout < /dev/null; \
			fi; \
		done; \
		${ECHO_MSG} ">> Couldn't CVS checkout ${PORTNAME}." ;\
		exit 1; \
	fi
.endif

makesrctarball:	fetch
	@cd ${DISTDIR}; \
	${ECHO_MSG} ">> Creating source tarball in ${DISTDIR}"; \
	${ECHO_MSG} ">> \"${DISTNAME}.${CVS_DATE_}.tar.gz\"."; \
	${TAR} cfz ${DISTNAME}.${CVS_DATE_}.tar.gz ${DISTNAME}

fetchsrctarball:
	@cd ${DISTDIR}; \
	file=${DISTNAME}.${CVS_DATE_}.tar.gz; \
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
	@cd ${WRKSRC}; ${MAKE} ${ALL_TARGET}

do-install:
	${INSTALL_DATA} ${WRKSRC}/compile/${UITYPE}/libh.a ${PREFIX}/lib/libh.a
	${INSTALL_DATA} ${WRKSRC}/compile/${UITYPE}/libh.so.0 ${PREFIX}/lib/libh.so.0
	${LN} -sf ${PREFIX}/lib/libh.so.0 ${PREFIX}/lib/libh.so
	${INSTALL_DATA} ${WRKSRC}/compile/${UITYPE}/libhui.a ${PREFIX}/lib/libhui.a
	${INSTALL_DATA} ${WRKSRC}/compile/${UITYPE}/libhui.so.0 ${PREFIX}/lib/libhui.so.0
	${LN} -sf ${PREFIX}/lib/libhui.so.0 ${PREFIX}/lib/libhui.so
.for H_NAME in disk file database sysinstall
	${INSTALL_DATA} ${WRKSRC}/compile/${UITYPE}/libh${H_NAME}.a ${PREFIX}/lib/libh${H_NAME}.a
	${INSTALL_DATA} ${WRKSRC}/compile/${UITYPE}/libh${H_NAME}.so.0 ${PREFIX}/lib/libh${H_NAME}.so.0
	${LN} -sf ${PREFIX}/lib/libh${H_NAME}.so.0 ${PREFIX}/lib/libh${H_NAME}.so
.endfor
.for T_NAME in tclhui tcl tclfile tcldisk tclsysinstall
	${INSTALL_DATA} ${WRKSRC}/compile/${UITYPE}/libh${T_NAME}.a ${PREFIX}/lib/libh${T_NAME}.a
	${INSTALL_DATA} ${WRKSRC}/compile/${UITYPE}/libh${T_NAME}.so.0 ${PREFIX}/lib/libh${T_NAME}.so.0
	${LN} -sf ${PREFIX}/lib/libh${T_NAME}.so.0 ${PREFIX}/lib/libh${T_NAME}.so
.endfor

	${MKDIR} ${PREFIX}/share/libh
	${INSTALL_DATA} ${WRKSRC}/release/*.tcl ${PREFIX}/share/libh

.for DIR in diskedit scripts pkgtools
	${MKDIR} ${PREFIX}/share/libh/${DIR}
	${INSTALL_DATA} ${WRKSRC}/release/${DIR}/*.tcl \
		${PREFIX}/share/libh/${DIR} 
.endfor

	${INSTALL_PROGRAM} ${WRKSRC}/compile/${UITYPE}/tclh.static ${PREFIX}/bin/tclh

.include <bsd.port.post.mk>
