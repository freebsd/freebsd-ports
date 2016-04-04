# Created by: Alexey V. Degtyarev
# $FreeBSD$

PORTNAME=	nagios-snmp-plugins-extras
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of Nagios plugins written in Perl to check devices with SNMP

LICENSE=	GPLv2

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	${PLUGINS}

RUN_DEPENDS+=	p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP \
		${LOCALBASE}/libexec/nagios/utils.pm:net-mgmt/nagios-plugins

PLUGINS=	check_snmp_boostedge.pl \
		check_snmp_cpfw.pl \
		check_snmp_css.pl \
		check_snmp_css_main.pl \
		check_snmp_env.pl \
		check_snmp_int.pl \
		check_snmp_linkproof_nhr.pl \
		check_snmp_load.pl \
		check_snmp_mem.pl \
		check_snmp_nsbox.pl \
		check_snmp_process.pl \
		check_snmp_storage.pl \
		check_snmp_vrrp.pl \
		check_snmp_win.pl

PLIST_FILES=	${PLUGINS:S,^,libexec/nagios/,}

WRKSRC=		${WRKDIR}/plugins

post-extract:
	${SED} -i "" -e "s#/tmp/#/var/tmp/#" \
		-e "s#/usr/local/nagios/libexec#${LOCALBASE}/libexec/nagios#" \
		${PLUGINS:S,^,${WRKSRC}/,}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${PLUGINS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/libexec/nagios/

.include <bsd.port.mk>
