# Created by: Paul Dlug<paul@nerdlabs.com>
# $FreeBSD$

PORTNAME=	nrpe
DISTVERSION=	2.15
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/nagios/${PORTNAME}-2.x/${PORTNAME}-${PORTVERSION}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Nagios Remote Plugin Executor

RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

LATEST_LINK=	nrpe2

USES=		perl5
USE_PERL5=	build
USE_RC_SUBR=	nrpe2
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	SSL ARGS

SSL_DESC=	Enable SSL support (disables plain-text server)
ARGS_DESC=	Enable command argument processing **Security Risk**

SSL_USE=		OPENSSL=yes
SSL_CONFIGURE_ON=	--enable-ssl --with-ssl=${OPENSSLDIR} \
			--with-ssl-inc=${OPENSSLINC} \
			--with-ssl-lib=${OPENSSLLIB}
SSL_CONFIGURE_OFF=	--disable-ssl
SSL_CFLAGS=		-I${OPENSSLINC}

ARGS_CONFIGURE_ON=	--enable-command-args
ARGS_CONFIGURE_OFF=	--disable-command-args

.include <bsd.port.options.mk>

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios
USERS=		${NAGIOSUSER}
GROUPS=		${NAGIOSGROUP}

NAGIOSUID=	181
NAGIOSGID=	${NAGIOSUID}
NRPE_PIDDIR?=	/var/run/nrpe2

CONFIGURE_ARGS+=--bindir=${PREFIX}/sbin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--sysconfdir=${PREFIX}/etc \
		--localstatedir=${NAGIOSDIR} \
		--with-nrpe-user=${NAGIOSUSER} \
		--with-nrpe-group=${NAGIOSGROUP}

PLIST_SUB=	NAGIOSDIR=${NAGIOSDIR} \
		NAGIOSUID=${NAGIOSUID} \
		NRPE_PIDDIR=${NRPE_PIDDIR}

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|/var/run/nrpe.pid|${NRPE_PIDDIR}/nrpe2.pid|g' \
		-e 's|/usr/lib/nagios/plugins/|${LOCALBASE}/libexec/nagios/|g' \
		-e 's|/usr/bin/sudo|${LOCALBASE}/bin/sudo|g' \
		${WRKSRC}/sample-config/nrpe.cfg.in
do-install:
	${INSTALL} -d ${STAGEDIR}${NRPE_PIDDIR}
	${INSTALL} -m 750 -d ${STAGEDIR}${NAGIOSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/nrpe ${STAGEDIR}${PREFIX}/sbin/nrpe2
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_PROGRAM} ${WRKSRC}/src/check_nrpe ${STAGEDIR}${PREFIX}/libexec/nagios/check_nrpe2
	${INSTALL_DATA} ${WRKSRC}/sample-config/nrpe.cfg ${STAGEDIR}${PREFIX}/etc/nrpe.cfg.sample

.include <bsd.port.mk>
