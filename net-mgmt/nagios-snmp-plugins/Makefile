# New ports collection makefile for:	nagios-snmp-plugins
# Date created:				19 Jul 2004
# Whom:					Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagios-snmp-plugins
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.hometree.net/pub/${PORTNAME}/

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Additional SNMP plugins for Nagios

LIB_DEPENDS=    netsnmp.7:${PORTSDIR}/net-mgmt/net-snmp

GNU_CONFIGURE=		yes
USE_AUTOMAKE_VER=	14
USE_AUTOCONF_VER=	213
USE_AUTOHEADER_VER=	213
USE_GETOPT_LONG=	yes
USE_GMAKE=		yes
USE_PERL5=		yes

NAGIOS_PLUGIN_DIR=	${PREFIX}/libexec/nagios

AUTOMAKE_ARGS=		--add-missing
CONFIGURE_ARGS=	--sbindir=${PREFIX}/share/nagios/cgi-bin \
		--libexecdir=${NAGIOS_PLUGIN_DIR} \
		--datadir=${PREFIX}/share/nagios \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=/var/spool/nagios \
		--with-snmp=${PREFIX}
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

# Workaround configure.in lameness.
CONFIGURE_ENV+= CPPFLAGS="`net-snmp-config --cflags`"

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOMAKE_ENV} ${ACLOCAL} \
		--acdir=${ACLOCAL_DIR})
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOMAKE_ENV} ${AUTOHEADER})
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOMAKE_ENV} ${AUTOMAKE} \
		${AUTOMAKE_ARGS})
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOMAKE_ENV} ${AUTOCONF} \
		${AUTOCONF_ARGS})

do-install:
	${MKDIR} ${NAGIOS_PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/check_snmp_disk ${NAGIOS_PLUGIN_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/check_snmp_proc ${NAGIOS_PLUGIN_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
