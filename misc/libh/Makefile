# New ports collection makefile for: lib
# Date Created:		19 September 2000
# Whom:			nra
#
# $FreeBSD$
#

PORTNAME=	libh
PORTVERSION=	0.2
CATEGORIES=	misc
# ${MASTER_SITES} is only for if CVS won't work, period.
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTNAME=	libh

MAINTAINER=	nra@FreeBSD.org

LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83 \
		tvision.0:${PORTSDIR}/devel/tvision
BUILD_DEPENDS= 	${X11BASE}/lib/libqt2.a:${PORTSDIR}/x11-toolkits/qt2-static

USE_QT_VER=	2
IS_INTERACTIVE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

DISTFILES!=	${CAT} ${FILESDIR}/distfiles

CVS_CMD?=	cvs -z3
# arbitrary date for now.
CVS_DATE=	Sat Mar 10 13:00:00 GMT 2001
CVS_DATE_!=	${ECHO} -n "${CVS_DATE}" | ${SED} 's/[ \t:]/_/g'
CVS_SITES?=	:pserver:anonymous@usw4.freebsd.org:/home/libh/cvs
DIRNAME=	${PORTNAME}-${PORTVERSION}
STAMPFILE=	${DISTDIR}/${DIRNAME}/.stamp

WRKSRC=		${WRKDIR}/libh-0.2

.if defined(BATCH)
do-fetch: fetchsrctarball
.else
do-fetch:
	@if [ ! -f ${STAMPFILE} ] || \
		[ "X${CVS_DATE}" != "X$$(${CAT} ${STAMPFILE})" ]; then \
		${ECHO_MSG} "No stamp file (or out of date)"; \
		if [ -f ${DISTDIR}/${DIRNAME}.${CVS_DATE_}.tar.gz ]; then \
			cd ${DISTDIR}; \
			${TAR} xfz ${DIRNAME}.${CVS_DATE_}.tar.gz \
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
			if ${CVS_CMD} -d $${CVS_SITE} co -D '${CVS_DATE}' ${DISTNAME}; then \
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
		${ECHO_MSG} ">> Couldn't CVS checkout ${DISTNAME}." ;\
		exit 1; \
	fi
.endif

makesrctarball:	fetch
	@cd ${DISTDIR}; \
	${ECHO_MSG} ">> Creating source tarball in ${DISTDIR}"; \
	${ECHO_MSG} ">> \"${DIRNAME}.${CVS_DATE_}.tar.gz\"."; \
	${TAR} cfz ${DIRNAME}.${CVS_DATE_}.tar.gz ${DIRNAME}

fetchsrctarball:
	@cd ${DISTDIR}; \
	file=${DIRNAME}.${CVS_DATE_}.tar.gz; \
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

do-extract:
	@${MKDIR} ${WRKDIR}
	@(cd ${DISTDIR}/${DIRNAME}/${DISTNAME} && \
		find . ! -name CVS -print | \
		cpio -pdmu ${WRKSRC} > /dev/null 2>&1)

do-build:
	@cd ${WRKSRC}; ${MAKE} ${ALL_TARGET}

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/common/libh.a ${PREFIX}/lib/libh.a
	${INSTALL_DATA} ${WRKSRC}/lib/common/libh.so.0 ${PREFIX}/lib/libh.so.0
	${LN} -sf ${PREFIX}/lib/libh.so.0 ${PREFIX}/lib/libh.so
	${INSTALL_DATA} ${WRKSRC}/lib/hui/libhui.a ${PREFIX}/lib/libhui.a
	${INSTALL_DATA} ${WRKSRC}/lib/hui/libhui.so.0 ${PREFIX}/lib/libhui.so.0
	${LN} -sf ${PREFIX}/lib/libhui.so.0 ${PREFIX}/lib/libhui.so
.for H_NAME in disk file database sysinstall
	${INSTALL_DATA} ${WRKSRC}/lib/${H_NAME}/libh${H_NAME}.a ${PREFIX}/lib/libh${H_NAME}.a
	${INSTALL_DATA} ${WRKSRC}/lib/${H_NAME}/libh${H_NAME}.so.0 ${PREFIX}/lib/libh${H_NAME}.so.0
	${LN} -sf ${PREFIX}/lib/libh${H_NAME}.so.0 ${PREFIX}/lib/libh${H_NAME}.so
.endfor
.for T_NAME in tclhui tcl tclfile tcldisk tclsysinstall
	${INSTALL_DATA} ${WRKSRC}/lib/tcl/libh${T_NAME}.a ${PREFIX}/lib/libh${T_NAME}.a
	${INSTALL_DATA} ${WRKSRC}/lib/tcl/libh${T_NAME}.so.0 ${PREFIX}/lib/libh${T_NAME}.so.0
	${LN} -sf ${PREFIX}/lib/libh${T_NAME}.so.0 ${PREFIX}/lib/libh${T_NAME}.so
.endfor
	${MKDIR} ${PREFIX}/share/libh
.for TCL_FILES in bin/setup doc/examples lib/disk lib/sysinstall
	${INSTALL_DATA} ${WRKSRC}/${TCL_FILES}/*.tcl ${PREFIX}/share/libh
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tclh/tclh.static ${PREFIX}/bin/tclh

.include <bsd.port.post.mk>
