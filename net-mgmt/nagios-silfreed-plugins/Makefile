# New ports collection makefile for:	nagios-silfreed-plugins
# Date created:				22 Jul 2004
# Whom:					Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagios-silfreed-plugins
PORTVERSION=	1.0
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.silfreed.net/download/progs/nagios/
DISTFILES=	check_snmp_counter-0.5.0.tar.gz \
		check_snmp_gauge-0.3.0.tar.gz \
		check_snmp_if-0.3.5.tar.gz \
		check_snmp_if_max-0.3.0.tar.gz \
		check_tcping-0.1.5.tar.gz \
		dns_delegation-0.1.0.tar.gz
.if defined(WITH_EXPECT_TOOLS)
DISTFILES+=	check_max_clients_route-0.1.6.tar.gz \
		check_pm3_clients_route-0.1.0.tar.gz
.endif
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Additional SNMP plugins for Nagios from silfreed.net

.include <bsd.port.pre.mk>

# Also uses traceroute, dig at runtime (in base system with hardcoded paths).
RUN_DEPENDS+=	\
	${LOCALBASE}/libexec/nagios:${PORTSDIR}/net-mgmt/nagios-plugins \
	${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}:net-mgmt/p5-Net-Netmask \
	${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}:net-mgmt/p5-Net-SNMP
.if defined(WITH_EXPECT_TOOLS)
RUN_DEPENDS+=	\
	${LOCALBASE}/bin/expect:${PORTSDIR}/lang/expect
.endif

USE_PERL5=	yes
NO_WRKSUBDIR=	yes

# XXX: Strictly speaking this shouldn't obey ${PREFIX}, as it has to be
#      installed to the same location as the Nagios plugins themselves.
NAGIOS_PLUGIN_DIR=	${LOCALBASE}/libexec/nagios

pre-everything::
.if !defined(WITH_EXPECT_TOOLS)
	@${ECHO_MSG} "${PORTNAME} has the following tunable option(s):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_EXPECT_TOOLS=yes  Installs additional plugins"
	@${ECHO_MSG} "                       which require lang/expect"
	@${ECHO_MSG} ""
.endif

do-build:
	( cd ${WRKSRC}/check_tcping-0.1.5 ; \
	  ${CC} ${CFLAGS} -o check_tcping check_tcping.c )

# Documentation
PLUGIN_README_DIRS=	\
	check_snmp_counter-0.5.0 \
	check_snmp_gauge-0.3.0 \
	check_snmp_if-0.3.5 \
	check_snmp_if_max-0.3.0 \
	check_tcping-0.1.5 \
	dns_delegation-0.1.0

.if defined(WITH_EXPECT_TOOLS)
PLUGIN_README_DIRS+=	\
	check_max_clients_route-0.1.6 \
	check_pm3_clients_route-0.1.0

CHECKMAXCLIENTS_SCRIPTS=	check_max_clients_route iproutecheck.pm \
				tnt tnt.exp
CHECKPM3CLIENTS_SCRIPTS=	check_pm3_clients_route pm3 pm3.exp

PLIST_SUB+=	EXPECTTOOLS=""
.else
PLIST_SUB+=	EXPECTTOOLS="@comment "
.endif

do-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/check_snmp_counter-0.5.0/check_snmp_counter ${NAGIOS_PLUGIN_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/check_snmp_gauge-0.3.0/check_snmp_gauge ${NAGIOS_PLUGIN_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/check_snmp_if-0.3.5/check_snmp_if ${NAGIOS_PLUGIN_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/check_snmp_if-0.3.5/gen_check_snmp_if_services ${NAGIOS_PLUGIN_DIR}
	${INSTALL_DATA} ${WRKSRC}/check_snmp_if-0.3.5/services-check_snmp_if.template ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/check_snmp_if_max-0.3.0/check_snmp_if_max ${NAGIOS_PLUGIN_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/check_snmp_if_max-0.3.0/gen_check_snmp_if_max_services ${NAGIOS_PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/check_tcping-0.1.5/check_tcping ${NAGIOS_PLUGIN_DIR}
.if defined(WITH_EXPECT_TOOLS)
.for i in ${CHECKMAXCLIENTS_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/check_max_clients_route-0.1.6/${i} ${NAGIOS_PLUGIN_DIR}
.endfor
.for i in ${CHECKPM3CLIENTS_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/check_pm3_clients_route-0.1.0/${i} ${NAGIOS_PLUGIN_DIR} )
.endfor
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PLUGIN_README_DIRS}
	${INSTALL_DATA} ${WRKSRC}/${i}/README ${DOCSDIR}/${i}.README
.endfor
.endif

.include <bsd.port.post.mk>
