# New ports collection makefile for:	webmin
# Date created:		Do  19 Nov 1998 21:13:55 CET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	webmin
PORTVERSION=	0.88
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://webadmin.sourceforge.net/webmin/updates/ \
		http://webadmin.sourceforge.net/webmin/download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${WEBMIN_MODULES} ${WEBMIN_THEMES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay

NO_BUILD=	yes
USE_PERL5=	yes
SCRIPTS_ENV+=	WRKDIR="${WRKDIR}"

WEBMIN_MODULES=	proftpd-0.88-1.wbm.gz majordomo-0.88-1.wbm.gz \
		useradmin-0.88-1.wbm.gz status-0.88-1.wbm.gz \
		samba-0.88-1.wbm.gz proc-0.88-1.wbm.gz \
		custom-0.88-1.wbm.gz
WEBMIN_THEMES=
		
post-extract:
	@if [ "${WEBMIN_MODULES}" != "" ]; then \
		for webmin_module in ${WEBMIN_MODULES}; do \
			${ECHO} "===> Unpacking updated module: $${webmin_module}"; \
			${TAR} --unlink -xzf ${DISTDIR}/$${webmin_module} -C ${WRKSRC}; \
		done; \
	fi
	@find ${WRKSRC} -name "*.bak" | xargs ${RM}

post-patch:
	@${CP} ${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.0 \
		${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.1
	@${CP} ${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.0 \
		${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.2
	@${CP} ${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.0 \
		${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.3
	@${CP} ${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.0 \
		${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.4
	@${CP} ${WRKSRC}/postfix/config ${WRKSRC}/postfix/config.sed
	@${SED}	-e "s@/usr/sbin/postfix@${LOCALBASE}/sbin/postfix@" \
		-e "s@/usr/sbin/postconf@${LOCALBASE}/sbin/postconf@" \
		-e "s@/etc/postfix/main.cf@${LOCALBASE}/etc/postfix/main.cf@" \
		-e "s@/usr/sbin/postalias@${LOCALBASE}/sbin/postalias@" \
		-e "s@/usr/sbin/postmap@${LOCALBASE}/sbin/postmap@" \
		${WRKSRC}/postfix/config.sed > ${WRKSRC}/postfix/config
	@${RM} ${WRKSRC}/postfix/config.sed

	@${CP} ${WRKSRC}/postgresql/config ${WRKSRC}/postgresql/config.sed
	@${SED}	-e "s@^hba_conf=.*@hba_conf=${LOCALBASE}/pgsql/data/pg_hba.conf@" \
		-e "s@^login=.*@login=pgsql@" \
		-e "s@^pid_file=.*@pid_file=${LOCALBASE}/pgsql/data/postmaster.pid@" \
		-e "s@^start_cmd=.*@start_cmd=${LOCALBASE}/etc/rc.d/010.pgsql.sh start@" \
		-e "s@^stop_cmd=.*@stop_cmd=${LOCALBASE}/etc/rc.d/010.pgsql.sh stop@" \
		-e "s@^psql=.*@psql=${LOCALBASE}/bin/psql@" \
		-e "s@^plib=.*@plib=${LOCALBASE}/lib@" \
		${WRKSRC}/postgresql/config.sed > ${WRKSRC}/postgresql/config

	@${RM} ${WRKSRC}/postgresql/config.sed

	@${CP} ${WRKSRC}/dhcpd/config-freebsd ${WRKSRC}/dhcpd/config-freebsd.sed
	@${SED}	-e "s@^dhcpd_conf=.*@dhcpd_conf=${LOCALBASE}/etc/dhcpd.conf@" \
		${WRKSRC}/dhcpd/config-freebsd.sed > ${WRKSRC}/dhcpd/config-freebsd
	@${RM} ${WRKSRC}/dhcpd/config-freebsd.sed

do-install:
	@${MKDIR} ${PREFIX}/lib/webmin
	@${CP} -r ${WRKSRC}/* ${PREFIX}/lib/webmin
	@cd ${PREFIX}/lib/webmin && find . -name "*.orig" -print \
		| xargs ${RM}
# we may have 2 levels of empty directories which cause the plist generation
# system to fail
	@cd ${PREFIX}/lib/webmin && find . -type d -empty -print \
		| xargs ${RMDIR}
	@cd ${PREFIX}/lib/webmin && find . -type d -empty -print \
		| xargs ${RMDIR}
	@${CP} ${WRKDIR}/webmin.sh ${PREFIX}/etc/rc.d/webmin.sh
	@${CHMOD} 554 ${PREFIX}/etc/rc.d/webmin.sh

post-install:
	@cd ${PREFIX} ; find lib/webmin -type f -o -type l | sort \
		> ${WRKDIR}/PLIST.lib-webmin
	@cd ${PREFIX} ; find lib/webmin -type d | sort -r \
	    	| ${SED} -e 's/^/@dirrm /g' \
		>> ${WRKDIR}/PLIST.lib-webmin

	@${ECHO} "r ${TMPPLIST}"		> ${WRKDIR}/ex.script
	@${ECHO} "/Insert PLIST.lib-webmin"	>> ${WRKDIR}/ex.script
	@${ECHO} "d"				>> ${WRKDIR}/ex.script
	@${ECHO} "r ${WRKDIR}/PLIST.lib-webmin"	>> ${WRKDIR}/ex.script
	@${ECHO} "x!"				>> ${WRKDIR}/ex.script
	@${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-lib-webmin
	@cd ${WRKDIR} ; ex < ex.script
# upgrade configuration if etc/webmin exists
	@[ ! -d ${PREFIX}/etc/webmin ] || echo | nostart=Y ${PREFIX}/lib/webmin/setup.sh
# run interactive setup if not in BATCH mode and no configuration exists
	@[ -n "$BATCH" ] || ([ -d ${PREFIX}/etc/webmin ] || nostart=Y ${PREFIX}/lib/webmin/setup.sh)
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
