PORTNAME=	nrpe
DISTVERSION=	4.1.1
DISTVERSIONPREFIX=	nrpe-
CATEGORIES=	net-mgmt

MAINTAINER=	bofh@FreeBSD.org
COMMENT?=	Nagios Remote Plugin Executor
WWW=		https://www.nagios.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		perl5
USE_GITHUB=	yes
GH_ACCOUNT=	NagiosEnterprises
USE_PERL5=	build
USE_RC_SUBR=	nrpe

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--bindir=${PREFIX}/sbin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--sysconfdir=${PREFIX}/etc \
		--with-inetd-type=inetd \
		--with-nrpe-user=${NAGIOSUSER} \
		--with-nrpe-group=${NAGIOSGROUP} \
		--with-piddir=${NRPE_PIDDIR}

SUB_FILES=	pkg-message
SUB_LIST+=	PIDDIR=${NRPE_PIDDIR}

USERS=		${NAGIOSUSER}
GROUPS=		${NAGIOSGROUP}

PLIST_SUB=	NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP} \
		NRPE_PIDDIR=${NRPE_PIDDIR}

OPTIONS_DEFINE=	SSL ARGS
OPTIONS_DEFAULT=NAGPLUGINS SSL
OPTIONS_RADIO=	PLUGINS
OPTIONS_RADIO_PLUGINS=	MONPLUGINS NAGPLUGINS

ARGS_DESC=	Enable command argument processing
MONPLUGINS_DESC=Use net-mgmt/monitoring-plugins
NAGPLUGINS_DESC=Use net-mgmt/nagios-plugins

ARGS_CONFIGURE_ENABLE=	command-args
MONPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/monitoring-plugins
NAGPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/nagios-plugins
SSL_USES=		ssl
SSL_CONFIGURE_ENABLE=	ssl
SSL_CONFIGURE_WITH=	ssl=${OPENSSLBASE} ssl-inc=${OPENSSLINC} ssl-lib=${OPENSSLLIB}
SSL_CFLAGS=		-I${OPENSSLINC}

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios

NRPE_PIDDIR?=	/var/run/nrpe

post-patch:
	@${REINPLACE_CMD} -e 's|/var/run/nrpe.pid|${NRPE_PIDDIR}/nrpe.pid|g' \
		-e 's|/usr/lib/nagios/plugins/|${LOCALBASE}/libexec/nagios/|g' \
		-e 's|/usr/bin/sudo|${LOCALBASE}/bin/sudo|g' \
		${WRKSRC}/sample-config/nrpe.cfg.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nrpe ${STAGEDIR}${PREFIX}/sbin/nrpe
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_PROGRAM} ${WRKSRC}/src/check_nrpe ${STAGEDIR}${PREFIX}/libexec/nagios/check_nrpe
	${INSTALL_DATA} ${WRKSRC}/sample-config/nrpe.cfg ${STAGEDIR}${PREFIX}/etc/nrpe.cfg.sample

.include <bsd.port.mk>
