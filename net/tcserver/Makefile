# New ports collection makefile for:	tcserver
# Date created:				06 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	tcserver
PORTVERSION=	1.1
CATEGORIES=	net
MASTER_SITES=
DISTNAME=	tcserver-freebsd_x86.sh
EXTRACT_SUFX=

MAINTAINER=	jedgar@FreeBSD.org

ONLY_FOR_ARCHS=	i386
RESTRICTED=	"LIC: redistribution not allowed"
IS_INTERACTIVE=	yes

WRKSRC=		${WRKDIR}/TCSERVER-1_1-freebsd_x86
NO_BUILD=	yes
LOG_DIR?=	/var/log/tcserver
PID_DIR?=	/var/run

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE='The source to this port may not be automatically fetched due to licensing restrictions.  You MUST fetch the source manually after registering at: http://streaming.entera.com/orderform.shtml  Once ${DISTFILES} has been downloaded, move it to ${DISTDIR} and then restart this build.'
.endif

pre-fetch:
	@for library in libc_r.so.3 libm.so.2 libstdc++.so.2 libg++.so.4; do \
		if [ -z "`ldconfig -r -elf | ${GREP} $$library`" ]; then \
			${ECHO}; \
			${ECHO} "This port requires the following FreeBSD 3.x compatibility"; \
			${ECHO} "libraries: libc_r.so.3, libstdc++.so.2, and libg++.so.4."; \
			${ECHO} "Please ensure they are installed and properly registered"; \
			${ECHO} "with the system (see ldconfig(8)).  These libraries may be"; \
			${ECHO} "obtained from compat3x and/or a recent FreeBSD 3.x system."; \
			${ECHO}; \
			exit 1; \
		fi \
	done

do-extract:
	@${MKDIR} ${WRKDIR}
	@${SED} -e 's|read extractdir|extractdir=\.|' \
		< ${DISTDIR}/${DISTNAME} > ${WRKDIR}/${DISTNAME}
	@(cd ${WRKDIR} && sh ${DISTNAME})

do-configure:
	for file in tcserver.cfg-dist scripts/tcserver.init; do \
		${MV} ${WRKSRC}/$$file ${WRKSRC}/$$file.orig; \
		${SED} -e 's|__PREFIX__|${PREFIX}|' \
			-e 's|__LOG_DIR__|${LOG_DIR}|' \
			-e 's|__PID_DIR__|${PID_DIR}|' \
			< ${WRKSRC}/$$file.orig > ${WRKSRC}/$$file; \
	done

do-install:
	${MKDIR} ${PREFIX}/share/tcserver/content
	${MKDIR} ${LOG_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/tcserver ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/tcserver.cfg-dist ${PREFIX}/etc/tcserver.cfg
	${INSTALL_DATA} ${WRKSRC}/tcserver.cfg-full ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/tcserver
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/docs/TeraCASTAdmin11.pdf \
		${PREFIX}/share/tcserver
.endif
	${INSTALL_DATA} ${WRKSRC}/content/tcserver-test.mov ${PREFIX}/share/tcserver/content
	if [ ! -f ${PREFIX}/etc/rc.d/tcserver.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/tcserver.sh startup file."; \
		${INSTALL_SCRIPT} ${WRKSRC}/scripts/tcserver.init \
			${PREFIX}/etc/rc.d/tcserver.sh; \
	fi

.include <bsd.port.post.mk>
