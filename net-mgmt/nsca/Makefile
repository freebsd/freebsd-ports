# New ports collection makefile for:	nsca
# Date created:		2003-11-18
# Whom:			Paul Dlug <paul@nerdlabs.com>
#
# $FreeBSD$
#

PORTNAME=	nsca
PORTVERSION=	2.4
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nagios

MAINTAINER=	paul@nerdlabs.com
COMMENT=	Nagios Service Check Acceptor

RUN_DEPENDS=	nagios:${PORTSDIR}/net-mgmt/nagios
LIB_DEPENDS=	mcrypt.8:${PORTSDIR}/security/libmcrypt

GNU_CONFIGURE=	yes
USE_PERL5=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --localstatedir=/var/spool/nagios

NAGIOS_DIR=	${LOCALBASE}/libexec/nagios
CONF_DIR=	${LOCALBASE}/etc/nagios

DOCS=		Changelog LEGAL README SECURITY

# NOTE: this port installs into ${LOCALBASE} instead of ${PREFIX}
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nsca ${NAGIOS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/send_nsca ${NAGIOS_DIR}
	${INSTALL_DATA} ${WRKSRC}/nsca.cfg ${CONF_DIR}/nsca.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/send_nsca.cfg ${CONF_DIR}/send_nsca.cfg.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
