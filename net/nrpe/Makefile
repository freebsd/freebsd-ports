# New ports collection makefile for:	nrpe
# Date created:				1 Aug 2002
# Whom:					Paul Dlug<paul@nerdlabs.com>
#
# $FreeBSD$
#

PORTNAME=	nrpe
PORTVERSION=	1.7
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nagios

MAINTAINER=	paul@nerdlabs.com

RUN_DEPENDS=    ${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net/nagios-plugins

GNU_CONFIGURE=	yes

pre-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${SED} -i bak -e "s=/usr/local/bin/nrpe=${PREFIX}/sbin/nrpe=" ${WRKSRC}/init-script.freebsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nrpe ${PREFIX}/sbin/nrpe
	${INSTALL_DATA} ${WRKSRC}/nrpe.cfg ${PREFIX}/etc/nrpe.cfg-sample
	${INSTALL_SCRIPT} ${WRKSRC}/init-script.freebsd ${PREFIX}/etc/rc.d/nrpe.sh

.include <bsd.port.mk>
