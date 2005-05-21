# New ports collection makefile for:	nrpe
# Date created:				1 Aug 2002
# Whom:					Paul Dlug<paul@nerdlabs.com>
#
# $FreeBSD$
#

PORTNAME=	nrpe
PORTVERSION=	1.9
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nagios

MAINTAINER=	paul@nerdlabs.com
COMMENT=	Nagios Remote Plugin Executor

RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
USE_RC_SUBR=	yes
SUB_FILES=	nrpe.sh pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

CONFIGURE_ARGS=	\
	    --libexecdir=${PREFIX}/libexec/nagios --sysconfdir=${PREFIX}/etc \
	    --sbindir=${PREFIX}/sbin --bindir=${PREFIX}/sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nrpe ${PREFIX}/sbin/nrpe
	${INSTALL_PROGRAM} ${WRKSRC}/src/check_nrpe \
		${PREFIX}/libexec/nagios/check_nrpe
	${INSTALL_DATA} ${WRKSRC}/nrpe.cfg ${PREFIX}/etc/nrpe.cfg-sample
	${INSTALL_SCRIPT} ${WRKDIR}/nrpe.sh ${PREFIX}/etc/rc.d

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
