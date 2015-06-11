# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nagios-snmp-plugins
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.softwareforge.de/releases/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Additional SNMP plugins for Nagios

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp

GNU_CONFIGURE=	yes
USES=		autoreconf gmake perl5
OPTIONS_DEFINE=	DOCS

NAGIOS_PLUGIN_DIR=	${PREFIX}/libexec/nagios

CONFIGURE_ARGS=	--sbindir=${PREFIX}/share/nagios/cgi-bin \
		--libexecdir=${NAGIOS_PLUGIN_DIR} \
		--datadir=${PREFIX}/share/nagios \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=/var/spool/nagios \
		--with-snmp=${PREFIX}
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

# Workaround configure.in lameness.
CPPFLAGS+=	`net-snmp-config --cflags`

do-install:
	${MKDIR} ${STAGEDIR}${NAGIOS_PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/check_snmp_disk ${STAGEDIR}${NAGIOS_PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/check_snmp_proc ${STAGEDIR}${NAGIOS_PLUGIN_DIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
