# New ports collection makefile for:	webmin
# Date created:		Do  19 Nov 1998 21:13:55 CET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	webmin
PORTVERSION=	0.84
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://webadmin.sourceforge.net/webmin/updates/ \
		http://webadmin.sourceforge.net/webmin/download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${WEBMIN_MODULES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
IGNOREFILES=	${WEBMIN_MODULES}

MAINTAINER=	olgeni@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay

NO_BUILD=	yes
IS_INTERACTIVE=	yes
USE_PERL5=	yes

WEBMIN_MODULES=	apache.wbm.gz mysql.wbm.gz status.wbm.gz file.wbm.gz

post-extract:
	@for webmin_module in ${WEBMIN_MODULES}; do \
		${TAR} xfz ${DISTDIR}/$${webmin_module} -C ${WRKSRC}; \
	done
	@find ${WRKSRC} -name "*.bak" | xargs ${RM}

post-patch:
	${CP} ${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.0 \
	${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.1
	${CP} ${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.0 \
	${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.2
	${CP} ${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.0 \
	${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.3
	${CP} ${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.0 \
	${WRKDIR}/webmin-${PORTVERSION}/bind8/config-freebsd-3.4
	${CP} ${WRKSRC}/postfix/config ${WRKSRC}/postfix/config.sed
	${SED}	-e "s@/usr/sbin/postfix@${LOCALBASE}/sbin/postfix@" \
		-e "s@/usr/sbin/postconf@${LOCALBASE}/sbin/postconf@" \
		-e "s@/etc/postfix/main.cf@${LOCALBASE}/etc/postfix/main.cf@" \
		-e "s@/usr/sbin/postalias@${LOCALBASE}/sbin/postalias@" \
		-e "s@/usr/sbin/postmap@${LOCALBASE}/sbin/postmap@" \
		${WRKSRC}/postfix/config.sed > ${WRKSRC}/postfix/config
	${RM} ${WRKSRC}/postfix/config.sed

	${CP} ${WRKSRC}/postgresql/config ${WRKSRC}/postgresql/config.sed
	${SED}	-e "s@^hba_conf=.*@hba_conf=${LOCALBASE}/pgsql/data/pg_hba.conf@" \
		-e "s@^login=.*@login=pgsql@" \
		-e "s@^pid_file=.*@pid_file=${LOCALBASE}/pgsql/data/postmaster.pid@" \
		-e "s@^start_cmd=.*@start_cmd=${LOCALBASE}/etc/rc.d/pgsql.sh start@" \
		-e "s@^stop_cmd=.*@stop_cmd=${LOCALBASE}/etc/rc.d/pgsql.sh stop@" \
		${WRKSRC}/postgresql/config.sed > ${WRKSRC}/postgresql/config
	${RM} ${WRKSRC}/postgresql/config.sed

do-install:
	@${MKDIR} ${PREFIX}/lib/webmin
	@${CP} -r ${WRKSRC}/* ${PREFIX}/lib/webmin
	@cd ${PREFIX}/lib/webmin && find . -name "*.orig" -print \
		| xargs ${RM}
	@cd ${PREFIX}/lib/webmin && ./setup.sh
	@${MV} /tmp/webmin.sh ${PREFIX}/etc/rc.d/webmin.sh
	@${CHMOD} 554 ${PREFIX}/etc/rc.d/webmin.sh

post-install:
	@${CP} ${PLIST} ${TMPPLIST}
	@find ${PREFIX}/lib/webmin -type f | ${SED} -e "s@${PREFIX}/@@" | sort >> ${TMPPLIST}
	@find ${PREFIX}/lib/webmin -type d | ${SED} -e "s@${PREFIX}/@@" | ${PERL} -e 'print (join ("\n", reverse map ("\@dirrm " . substr ($$_, 0, -1), <STDIN>)) . "\n");' >> ${TMPPLIST}

.include <bsd.port.mk>
