# Created by: Paul Dlug<paul@nerdlabs.com>
# $FreeBSD$

PORTNAME=	nrpe
DISTVERSION=	2.14
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/nagios/${PORTNAME}-2.x/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios Remote Plugin Executor

RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

LATEST_LINK=	nrpe2

USES=		perl5
USE_PERL5=	build
USE_RC_SUBR=	nrpe2

CONFLICTS=	nrpe-1.*

OPTIONS_DEFINE=	SSL ARGS
SSL_DESC=	Enable SSL support (disables plain-text server)
ARGS_DESC=	Enable command argument processing **Security Risk**

GNU_CONFIGURE=	yes

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios
USERS=		${NAGIOSUSER}
GROUPS=		${NAGIOSGROUP}

NAGIOSUID=	181
NAGIOSGID=	${NAGIOSUID}

CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--sysconfdir=${PREFIX}/etc \
		--localstatedir=${NAGIOSDIR} \
		--with-nrpe-user=${NAGIOSUSER} \
		--with-nrpe-group=${NAGIOSGROUP}

PLIST_SUB=	NAGIOSDIR=${NAGIOSDIR} \
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP} \
		NAGIOSUID=${NAGIOSUID} \
		NAGIOSGID=${NAGIOSGID}

SUB_FILES=	pkg-install \
		pkg-deinstall \
		pkg-message

SUB_LIST=	PREFIX=${PREFIX} \
		${PLIST_SUB}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSSL}
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--enable-ssl
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if ${PORT_OPTIONS:MARGS}
CONFIGURE_ARGS+=	--enable-command-args
.else
CONFIGURE_ARGS+=	--disable-command-args
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/var/run/nrpe.pid#/var/run/nrpe2/nrpe2.pid#g' \
		-e 's#/usr/lib/nagios/plugins/#${LOCALBASE}/libexec/nagios/#g' \
		-e 's#/usr/bin/sudo#${LOCALBASE}/bin/sudo#g' \
		${WRKSRC}/sample-config/nrpe.cfg.in

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nrpe ${PREFIX}/sbin/nrpe2
	${INSTALL_PROGRAM} ${WRKSRC}/src/check_nrpe ${PREFIX}/libexec/nagios/check_nrpe2
	${INSTALL_DATA} ${WRKSRC}/sample-config/nrpe.cfg ${PREFIX}/etc/nrpe.cfg-sample
	${MKDIR} ${NAGIOSDIR}

post-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} POST-INSTALL
	@[ -f ${PREFIX}/etc/nrpe.cfg ] || \
	    ${CP} -p ${PREFIX}/etc/nrpe.cfg-sample ${PREFIX}/etc/nrpe.cfg
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
