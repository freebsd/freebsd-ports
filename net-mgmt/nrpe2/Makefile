# New ports collection makefile for:	nrpe
# Date created:				1 Aug 2002
# Whom:					Paul Dlug<paul@nerdlabs.com>
#
# $FreeBSD$
#

PORTNAME=	nrpe2
PORTVERSION=	2.11
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nagios
DISTNAME=	nrpe-${PORTVERSION}

MAINTAINER=	jarrod@netleader.com.au
COMMENT=	Nagios Remote Plugin Executor

RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

USE_PERL5_BUILD=	yes
USE_RC_SUBR=	nrpe2

OPTIONS=	SSL "SSL support" off \
		ARGS "Enable command arguments *POTENTIAL SECURITY RISK*" off

GNU_CONFIGURE=	yes

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

NAGIOSUID=	181
NAGIOSGID=	${NAGIOSUID}

CONFIGURE_ARGS+=	--bindir=${PREFIX}/sbin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--sysconfdir=${PREFIX}/etc \
		--with-nrpe-user=${NAGIOSUSER} \
		--with-nrpe-group=${NAGIOSGROUP}

PLIST_FILES=	sbin/nrpe2 etc/nrpe.cfg-sample libexec/nagios/check_nrpe2

SUB_VARS=	NAGIOSDIR=${NAGIOSDIR} \
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP} \
		NAGIOSUID=${NAGIOSUID} \
		NAGIOSGID=${NAGIOSGID}

SUB_FILES=	pkg-install \
		pkg-deinstall \
		pkg-message

SUB_LIST+=	${SUB_VARS}
PLIST_SUB+=	${SUB_VARS}

.include <bsd.port.pre.mk>

.if defined(WITH_SSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--enable-ssl
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if defined(WITH_ARGS)
CONFIGURE_ARGS+=	--enable-command-args
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#nrpe.pid#nrpe2.pid#g' \
		-e 's#/usr/lib/nagios/plugins/#${LOCALBASE}/libexec/nagios/#g' \
		-e 's#/usr/bin/sudo#${LOCALBASE}/bin/sudo#g' \
		${WRKSRC}/sample-config/nrpe.cfg.in

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nrpe ${PREFIX}/sbin/nrpe2
	${INSTALL_PROGRAM} ${WRKSRC}/src/check_nrpe ${PREFIX}/libexec/nagios/check_nrpe2
	${INSTALL_DATA} ${WRKSRC}/sample-config/nrpe.cfg ${PREFIX}/etc/nrpe.cfg-sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
