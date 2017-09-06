# Created by: Paul Dlug<paul@nerdlabs.com>
# $FreeBSD$

PORTNAME=	nrpe
DISTVERSION=	2.15
PORTREVISION=	7
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/nagios/${PORTNAME}-2.x/${PORTNAME}-${PORTVERSION}

MAINTAINER=	zeising@FreeBSD.org
COMMENT?=	Nagios Remote Plugin Executor

LICENSE=	GPLv2

CONFLICTS?=	nrpe-ssl nrpe3

USES=		perl5
USE_PERL5=	build
USE_RC_SUBR=	nrpe2
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	SSL ARGS
OPTIONS_RADIO=	PLUGINS
OPTIONS_RADIO_PLUGINS=	MONPLUGINS NAGPLUGINS
OPTIONS_DEFAULT=ARGS NAGPLUGINS

SSL_DESC=	Enable SSL support (disables plain-text server)
ARGS_DESC=	Enable command argument processing
NAGPLUGINS_DESC=Use net-mgmt/nagios-plugins
MONPLUGINS_DESC=Use net-mgmt/monitoring-plugins

SSL_USES=		ssl
SSL_CONFIGURE_ON=	--enable-ssl --with-ssl=${OPENSSLDIR} \
			--with-ssl-inc=${OPENSSLINC} \
			--with-ssl-lib=${OPENSSLLIB}
SSL_CONFIGURE_OFF=	--disable-ssl
SSL_CFLAGS=		-I${OPENSSLINC}

ARGS_CONFIGURE_ON=	--enable-command-args
ARGS_CONFIGURE_OFF=	--disable-command-args

MONPLUGINS_RUN_DEPENDS= ${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/monitoring-plugins
NAGPLUGINS_RUN_DEPENDS= ${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/nagios-plugins

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
USERS=		${NAGIOSUSER}
GROUPS=		${NAGIOSGROUP}

NRPE_PIDDIR?=	/var/run/nrpe2

CONFIGURE_ARGS+=--bindir=${PREFIX}/sbin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--sysconfdir=${PREFIX}/etc \
		--with-nrpe-user=${NAGIOSUSER} \
		--with-nrpe-group=${NAGIOSGROUP}

PLIST_SUB=	NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP} \
		NRPE_PIDDIR=${NRPE_PIDDIR}
SUB_LIST+=	PIDDIR=${NRPE_PIDDIR}

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|/var/run/nrpe.pid|${NRPE_PIDDIR}/nrpe2.pid|g' \
		-e 's|/usr/lib/nagios/plugins/|${LOCALBASE}/libexec/nagios/|g' \
		-e 's|/usr/bin/sudo|${LOCALBASE}/bin/sudo|g' \
		${WRKSRC}/sample-config/nrpe.cfg.in
do-install:
	${INSTALL} -d ${STAGEDIR}${NRPE_PIDDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/nrpe ${STAGEDIR}${PREFIX}/sbin/nrpe2
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_PROGRAM} ${WRKSRC}/src/check_nrpe ${STAGEDIR}${PREFIX}/libexec/nagios/check_nrpe2
	${INSTALL_DATA} ${WRKSRC}/sample-config/nrpe.cfg ${STAGEDIR}${PREFIX}/etc/nrpe.cfg.sample

.include <bsd.port.mk>
