# New ports collection makefile for:	usermin
# Date created:		10 Nov 2002
# Whom:			olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	usermin
PORTVERSION=	0.970
CATEGORIES=	sysutils
MASTER_SITES=	http://www.webmin.com/uupdates/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	webadmin
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${USERMIN_MODULES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Authen/PAM.pm:${PORTSDIR}/security/p5-Authen-PAM

NO_BUILD=	yes
USE_PERL5=	yes
SCRIPTS_ENV+=	WRKDIR="${WRKDIR}"

USERMIN_MODULES=	mysql-0.970-1.wbm.gz

USERMIN_THEMES=

post-extract:
	@if [ "${USERMIN_MODULES}" != "" ]; then \
		for usermin_module in ${USERMIN_MODULES}; do \
			${ECHO} "===> Unpacking updated module: $${usermin_module}"; \
			${TAR} --unlink -xzf ${DISTDIR}/$${usermin_module} -C ${WRKSRC}; \
		done; \
	fi
	@find ${WRKSRC} -name "*.bak" | ${XARGS} ${RM}

do-install:
	@${MKDIR} ${PREFIX}/lib/usermin
	@${CP} -r ${WRKSRC}/* ${PREFIX}/lib/usermin
	@cd ${PREFIX}/lib/usermin && find . -name "*.orig" -print \
		| ${XARGS} ${RM}
# we may have 2 levels of empty directories which cause the plist generation
# system to fail
	@cd ${PREFIX}/lib/usermin && find . -type d -empty -print \
		| ${XARGS} ${RMDIR}
	@cd ${PREFIX}/lib/usermin && find . -type d -empty -print \
		| ${XARGS} ${RMDIR}
	@${CP} ${WRKDIR}/usermin.sh ${PREFIX}/etc/rc.d/usermin.sh-dist
	@${CHMOD} 554 ${PREFIX}/etc/rc.d/usermin.sh-dist

post-install:
	@cd ${PREFIX} ; find lib/usermin -type f -o -type l | sort \
		> ${WRKDIR}/PLIST.lib-usermin
	@cd ${PREFIX} ; find lib/usermin -type d | sort -r \
		| ${SED} -e 's/^/@dirrm /g' \
		>> ${WRKDIR}/PLIST.lib-usermin

	@${ECHO_CMD} "r ${TMPPLIST}"			> ${WRKDIR}/ex.script
	@${ECHO_CMD} "/Insert PLIST.lib-usermin"	>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "d"				>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "r ${WRKDIR}/PLIST.lib-usermin"	>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "x!"				>> ${WRKDIR}/ex.script
	@${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-lib-usermin
	@cd ${WRKDIR} ; ex < ex.script
# stop usermin if configured and enabled at startup
	@[ -n "${BATCH}" ] || ([ ! -d ${PREFIX}/etc/usermin ] || [ ! -x ${PREFIX}/etc/rc.d/usermin.sh ] || ${PREFIX}/etc/rc.d/usermin.sh stop > /dev/null)
# upgrade configuration if etc/usermin exists
	@[ ! -d ${PREFIX}/etc/usermin ] || ${ECHO_CMD} | nostart=Y ${PREFIX}/lib/usermin/setup.sh
# run interactive setup if not in BATCH mode and no configuration exists
	@[ -n "${BATCH}" ] || ([ -d ${PREFIX}/etc/usermin ] || nostart=Y ${PREFIX}/lib/usermin/setup.sh)
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
