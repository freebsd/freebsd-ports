# New ports collection makefile for:	nagios-openldap-plugins
# Date created: 			26 Feb 2012
# Whom:					Ryan Steinmetz <zi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	openldap-plugins
PORTVERSION=	0.3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://tools.ltb-project.org/attachments/download/152/ \
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

PLIST_FILES=	libexec/nagios/check_ldap_dn.pl \
		libexec/nagios/check_ldap_query.pl \
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
	${INSTALL_SCRIPT} ${WRKSRC}/check_ldap_dn.pl ${PREFIX}/libexec/nagios/
	${INSTALL_SCRIPT} ${WRKSRC}/check_ldap_query.pl ${PREFIX}/libexec/nagios/
	${INSTALL_SCRIPT} ${WRKSRC}/check_ldap_slurpd_status.pl ${PREFIX}/libexec/nagios/
	${INSTALL_SCRIPT} ${WRKSRC}/check_ldap_syncrepl_status.pl ${PREFIX}/libexec/nagios/
	${INSTALL_SCRIPT} ${WRKSRC}/check_ldap_time.pl ${PREFIX}/libexec/nagios/
	${INSTALL_SCRIPT} ${WRKSRC}/restart_slapd.sh ${PREFIX}/libexec/nagios/

.include <bsd.port.mk>
