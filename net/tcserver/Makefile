# New ports collection makefile for:	elsa
# Version required:			1.0
# Date created:				06 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	elsa-freebsd_x86
PKGNAME=	elsa-1.0b
CATEGORIES=	net
MASTER_SITES=	""

MAINTAINER=	jedgar@fxp.org

ONLY_FOR_ARCHS=	i386
RESTRICTED=	"LIC: redistribution not allowed"

WRKSRC=		${WRKDIR}/ELSA-1_0b-016-freebsd_x86
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE='The source to this port may not be automatically fetched due to licensing restrictions.  You MUST fetch the source manually after registering at: http://streaming.entera.com/orderform.shtml  Once ${DISTFILES} has been downloaded, move it to ${DISTDIR} and then restart this build.'
.endif

do-configure:
	@${MV} ${WRKSRC}/elsa.cfg ${WRKSRC}/elsa.cfg.orig
	@${SED} -e 's|CHANGE_ME|${PREFIX}/share/elsa|' \
		< ${WRKSRC}/elsa.cfg.orig > ${WRKSRC}/elsa.cfg

do-install:
	${MKDIR} ${PREFIX}/share/elsa/content
	${MKDIR} /var/log/elsa
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
