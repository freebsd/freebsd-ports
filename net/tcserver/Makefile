# New ports collection makefile for:	elsa
# Version required:			1.0b-017
# Date created:				06 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	elsa-freebsd_x86
PKGNAME=	elsa-1.0b-017
CATEGORIES=	net
MASTER_SITES=	""

MAINTAINER=	jedgar@fxp.org

ONLY_FOR_ARCHS=	i386
RESTRICTED=	"LIC: redistribution not allowed"

WRKSRC=		${WRKDIR}/ELSA-1_0b-017-freebsd_x86
NO_BUILD=	yes
LOG_DIR?=	/var/log/elsa

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE='The source to this port may not be automatically fetched due to licensing restrictions.  You MUST fetch the source manually after registering at: http://streaming.entera.com/orderform.shtml  Once ${DISTFILES} has been downloaded, move it to ${DISTDIR} and then restart this build.'
.endif

pre-fetch:
	@for library in libc_r.so.3 libstdc++.so.2 libg++.so.4; do \
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

do-configure:
	@${PERL} -pi.orig -e 's|__PREFIX__|${PREFIX}|' ${WRKSRC}/elsa.cfg
	@${PERL} -pi.orig -e 's|__LOG_DIR__|${LOG_DIR}|' ${WRKSRC}/elsa.cfg

do-install:
	${MKDIR} ${PREFIX}/share/elsa/content
	${MKDIR} ${LOG_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/elsa ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/elsa.cfg ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/elsa
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/elsa
	${INSTALL_DATA} ${WRKSRC}/content/elsa-test.mov ${PREFIX}/share/elsa/content

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/elsa.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/elsa.sh startup file."; \
		${ECHO}  "#!/bin/sh" > ${PREFIX}/etc/rc.d/elsa.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/elsa ] && ${PREFIX}/sbin/elsa -d ${PREFIX}/etc > /dev/null & && ${ECHO} -n ' elsa'" >> ${PREFIX}/etc/rc.d/elsa.sh; \
		${CHMOD} 555 ${PREFIX}/etc/rc.d/elsa.sh; \
	fi

.include <bsd.port.post.mk>
