# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nagios-snmp-plugins
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.softwareforge.de/releases/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Additional SNMP plugins for Nagios

LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp

USES=		gmake perl5
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake14 autoheader autoconf
OPTIONS_DEFINE=	DOCS

NAGIOS_PLUGIN_DIR=	${PREFIX}/libexec/nagios

AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS=	--sbindir=${PREFIX}/share/nagios/cgi-bin \
		--libexecdir=${NAGIOS_PLUGIN_DIR} \
		--datadir=${PREFIX}/share/nagios \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=/var/spool/nagios \
		--with-snmp=${PREFIX}
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

# Workaround configure.in lameness.
CPPFLAGS+=	`net-snmp-config --cflags`

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOMAKE_ENV} ${ACLOCAL} \
		--acdir=${ACLOCAL_DIR})
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOMAKE_ENV} ${AUTOHEADER})
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOMAKE_ENV} ${AUTOMAKE} \
		${AUTOMAKE_ARGS})
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOMAKE_ENV} ${AUTOCONF} \
		${AUTOCONF_ARGS})

do-install:
	${MKDIR} ${STAGEDIR}${NAGIOS_PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/check_snmp_disk ${STAGEDIR}${NAGIOS_PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/check_snmp_proc ${STAGEDIR}${NAGIOS_PLUGIN_DIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
