# New ports collection makefile for:	nrpe
# Date created:				1 Aug 2002
# Whom:					Paul Dlug<paul@nerdlabs.com>
#
# $FreeBSD$
#

PORTNAME=	nrpe
PORTVERSION=	1.9
PORTREVISION=	5
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nagios

MAINTAINER=	jarrod@netleader.com.au
COMMENT=	Nagios Remote Plugin Executor

DEPRECATED=	Obsolete version, consider migration to net-mgmt/nrpe2
EXPIRATION_DATE=	2009-04-17

RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_RC_SUBR=	nrpe
SUB_FILES=	pkg-message

CONFIGURE_ARGS=	\
	    --libexecdir=${PREFIX}/libexec/nagios --sysconfdir=${PREFIX}/etc \
	    --sbindir=${PREFIX}/sbin --bindir=${PREFIX}/sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nrpe ${PREFIX}/sbin/nrpe
	${INSTALL_PROGRAM} ${WRKSRC}/src/check_nrpe \
		${PREFIX}/libexec/nagios/check_nrpe
	${INSTALL_DATA} ${WRKSRC}/nrpe.cfg ${PREFIX}/etc/nrpe.cfg-sample

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
