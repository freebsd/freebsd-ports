# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openldap-plugins
PORTVERSION=	0.5
CATEGORIES=	net-mgmt
MASTER_SITES=	http://tools.ltb-project.org/attachments/download/629/ \
		http://mirrors.rit.edu/zi/
PKGNAMEPREFIX=	nagios-
DISTNAME=	ltb-project-nagios-plugins-${PORTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Nagios Plugins to monitor OpenLDAP

LICENSE=	GPLv2

RUN_DEPENDS=	p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap \
		p5-Date-Manip>=6.30:${PORTSDIR}/devel/p5-Date-Manip \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes

PORTSCOUT=	ignore:1

NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run

PLIST_FILES=	libexec/nagios/check_berkeleydb_locks.pl \
		libexec/nagios/check_ldap_dn.pl \
		libexec/nagios/check_ldap_query.pl \
		libexec/nagios/check_ldap_monitor.pl \
		libexec/nagios/check_ldap_slurpd_status.pl \
		libexec/nagios/check_ldap_syncrepl_status.pl \
		libexec/nagios/check_ldap_time.pl \
		libexec/nagios/restart_slapd.sh
PLIST_DIRSTRY=	libexec/nagios

WRKSRC=		${WRKDIR}/${DISTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/init.d/|${LOCALBASE}/etc/rc.d/|g' \
		-e 's|/var/run/slapd|/var/run/openldap|g' \
		${WRKSRC}/restart_slapd.sh
	@${REINPLACE_CMD} -e 's|/usr/local/nagios/libexec|${PREFIX}/libexec/nagios|g' \
		${WRKSRC}/*.pl

do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	@(cd ${WRKSRC} && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/libexec/nagios/)

.include <bsd.port.mk>
