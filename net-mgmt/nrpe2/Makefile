# New ports collection makefile for:	nrpe
# Date created:				1 Aug 2002
# Whom:					Paul Dlug<paul@nerdlabs.com>
#
# $FreeBSD$
#

PORTNAME=		nrpe2
PORTVERSION=		2.0
PORTREVISION=		0
CATEGORIES=		net-mgmt
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nagios
DISTNAME=		nrpe-${PORTVERSION}

MAINTAINER=		paul@nerdlabs.com
COMMENT=		Nagios Remote Plugin Executor

RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec/nagios --bindir=${PREFIX}/sbin --sysconfdir=${PREFIX}/etc

.if defined(WITH_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--enable-ssl
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nrpe ${PREFIX}/sbin/nrpe2
	${INSTALL_PROGRAM} ${WRKSRC}/src/check_nrpe ${PREFIX}/libexec/nagios/check_nrpe2
	${INSTALL_DATA} ${WRKSRC}/nrpe.cfg ${PREFIX}/etc/nrpe.cfg-sample
	${INSTALL_SCRIPT} ${WRKSRC}/init-script.freebsd ${PREFIX}/etc/rc.d/nrpe.sh

.include <bsd.port.mk>
