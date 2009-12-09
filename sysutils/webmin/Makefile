# New ports collection makefile for:	webmin
# Date created:		Do  19 Nov 1998 21:13:55 CET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	webmin
PORTVERSION=	1.500
CATEGORIES=	sysutils
MASTER_SITES=	http://download.webmin.com/updates/:up \
		SF/webadmin/${PORTNAME}/${PORTVERSION}:sf \
		${MASTER_SITE_LOCAL:S/$/:up/}
MASTER_SITE_SUBDIR=	olgeni/:up
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sf ${WEBMIN_MODULES:S/gz$/gz:up/}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Web-based interface for system administration for Unix

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${SITE_PERL}/${PERL_ARCH}/Authen/PAM.pm:${PORTSDIR}/security/p5-Authen-PAM

NO_BUILD=	yes
USE_PERL5=	yes
USE_RC_SUBR=	webmin.sh
SUB_LIST=	PERL5=${PERL}

WEBMIN_MODULES=

post-extract:
	@if [ "${WEBMIN_MODULES}" != "" ]; then \
		for webmin_module in ${WEBMIN_MODULES}; do \
			${ECHO} "===> Unpacking updated module: $${webmin_module}"; \
			${TAR} --unlink -xzf ${DISTDIR}/$${webmin_module} -C ${WRKSRC}; \
		done; \
	fi

post-patch:
.for file in	config-freebsd apache/config-freebsd \
		bind8/config-freebsd-2.1-2.2 \
		dhcpd/config-freebsd frox/config-freebsd \
		heartbeat/config-freebsd logrotate/config-freebsd \
		majordomo/config mysql/config-freebsd \
		postfix/config-freebsd postgresql/config-freebsd \
		procmail/config-freebsd proftpd/config-freebsd \
		samba/config-freebsd sentry/config-freebsd-4.10 \
		sentry/config-freebsd-4.9 sentry/config-freebsd-5.0-\* \
		spam/config-freebsd squid/config-freebsd \
		stunnel/config usermin/config webalizer/config-freebsd \
		wuftpd/config-freebsd xinetd/config-freebsd
	@${REINPLACE_CMD} -e "s@%%PREFIX%%@${PREFIX}@g" ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e "s@%%PREFIX%%@${PREFIX}@g" ${WRKSRC}/setup.sh
	@${FIND} ${WRKSRC} -name "*.cgi" -print \
		| ${XARGS} ${REINPLACE_CMD} -e "s@#!/usr/local/bin/perl@#!${PERL}@"
	@${FIND} ${WRKSRC} -name "*.cgi" -print \
		| ${XARGS} ${REINPLACE_CMD} -e "s@#!/usr/bin/perl@#!${PERL}@"
	@${FIND} ${WRKSRC} -name "*.pl" -print \
		| ${XARGS} ${REINPLACE_CMD} -e "s@#!/usr/local/bin/perl@#!${PERL}@"
	@${FIND} ${WRKSRC} -name "*.pl" -print \
		| ${XARGS} ${REINPLACE_CMD} -e "s@#!/usr/bin/perl@#!${PERL}@"
	@${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM}
	@${FIND} ${WRKSRC} -name "*.bak" -print | ${XARGS} ${RM}

do-install:
	@${MKDIR} ${PREFIX}/lib/webmin
	@${CP} -r ${WRKSRC}/* ${PREFIX}/lib/webmin

post-install:
	@cd ${WRKSRC} ; ${FIND} * -type f -o -type l | ${SORT} | ${AWK} \
		'{ print "lib/webmin/" $$1 }' > ${WRKDIR}/PLIST.lib-webmin
	@cd ${WRKSRC} ; ${FIND} * -type d -empty | ${SORT} -r | ${AWK} \
		'{ print "lib/webmin/" $$1 }' | ${SED} -e 's#^#@exec mkdir -p %D/#g' \
		>> ${WRKDIR}/PLIST.lib-webmin
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
	@if [ -d ${PREFIX}/etc/webmin ]; then \
		${PREFIX}/lib/webmin/setup.sh; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
