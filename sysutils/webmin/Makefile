# New ports collection makefile for:	webmin
# Date created:		Do  19 Nov 1998 21:13:55 CET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	webmin
PORTVERSION=	1.130
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.webmin.com/updates/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	webadmin
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${WEBMIN_MODULES} ${WEBMIN_THEMES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Web-based interface for system administration for Unix

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${SITE_PERL}/${PERL_ARCH}/Authen/PAM.pm:${PORTSDIR}/security/p5-Authen-PAM

NO_BUILD=	yes
USE_PERL5=	yes
USE_SIZE=	yes
SCRIPTS_ENV+=	WRKDIR="${WRKDIR}"

WEBMIN_MODULES=	firewall-1.130-1.wbm.gz \
		htaccess-htpasswd-1.130-1.wbm.gz \
		logrotate-1.130-1.wbm.gz \
		quota-1.130-1.wbm.gz \
		shorewall-1.130-1.wbm.gz \
		webmin-1.130-1.wbm.gz

WEBMIN_THEMES=

post-extract:
	@if [ "${WEBMIN_MODULES}" != "" ]; then \
		for webmin_module in ${WEBMIN_MODULES}; do \
			${ECHO} "===> Unpacking updated module: $${webmin_module}"; \
			${TAR} --unlink -xzf ${DISTDIR}/$${webmin_module} -C ${WRKSRC}; \
		done; \
	fi
	@${FIND} ${WRKSRC} -name "*.bak" | ${XARGS} ${RM}

post-patch:
	@${CP} ${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.0 \
		${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.1
	@${CP} ${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.0 \
		${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.2
	@${CP} ${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.0 \
		${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.3
	@${CP} ${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.0 \
		${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.4
.for file in	config-freebsd apache/config-freebsd bind8/config-freebsd-2.1 \
		bind8/config-freebsd-2.2 dhcpd/config-freebsd majordomo/config \
		mysql/config-freebsd postfix/config-freebsd \
		postgresql/config-freebsd proftpd/config-freebsd \
		samba/config-freebsd squid/config-freebsd stunnel/config \
		wuftpd/config-freebsd xinetd/config-freebsd \
		usermin/config
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor
	@${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM}
	@${FIND} ${WRKSRC} -name "*.bak" -print | ${XARGS} ${RM}
# we may have 2 levels of empty directories which cause the plist generation
# system to fail
	@${FIND} ${WRKSRC} -type d -empty -print | ${XARGS} ${RMDIR}
	@${FIND} ${WRKSRC} -type d -empty -print | ${XARGS} ${RMDIR}

do-install:
	@${MKDIR} ${PREFIX}/lib/webmin
	@${CP} -r ${WRKSRC}/* ${PREFIX}/lib/webmin
	@${CP} ${WRKDIR}/webmin.sh ${PREFIX}/etc/rc.d/webmin.sh-dist
	@${CHMOD} 554 ${PREFIX}/etc/rc.d/webmin.sh-dist

post-install:
	@cd ${WRKSRC} ; ${FIND} * -type f -o -type l | ${SORT} | ${AWK} \
		'{ print "lib/webmin/" $$1 }' > ${WRKDIR}/PLIST.lib-webmin
	@cd ${WRKSRC} ; ${FIND} * -type d | ${SORT} -r | ${AWK} \
		'{ print "lib/webmin/" $$1 }' | ${SED} -e 's/^/@dirrm /g' \
		>> ${WRKDIR}/PLIST.lib-webmin

	@${ECHO_CMD} "r ${TMPPLIST}"			> ${WRKDIR}/ex.script
	@${ECHO_CMD} "/Insert PLIST.lib-webmin"		>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "d"				>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "r ${WRKDIR}/PLIST.lib-webmin"	>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "x!"				>> ${WRKDIR}/ex.script
	@${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-lib-webmin
	@cd ${WRKDIR} ; ex < ex.script
# stop webmin if configured and enabled at startup
	@[ -n "${BATCH}" ] || ([ ! -d ${PREFIX}/etc/webmin ] || [ ! -x ${PREFIX}/etc/rc.d/webmin.sh ] || ${PREFIX}/etc/rc.d/webmin.sh stop > /dev/null)
# upgrade configuration if etc/webmin exists
	@[ ! -d ${PREFIX}/etc/webmin ] || ${ECHO_CMD} | nostart=Y ${PREFIX}/lib/webmin/setup.sh
# run interactive setup if not in BATCH mode and no configuration exists
	@[ -n "${BATCH}" ] || ([ -d ${PREFIX}/etc/webmin ] || nostart=Y ${PREFIX}/lib/webmin/setup.sh)
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
