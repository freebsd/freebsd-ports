# New ports collection makefile for:   netustad
# Date created:                 4 July 2004
# Whom:                         ozkan@enderunix.org
#
# $FreeBSD$
#

PORTNAME=	netustad
PORTVERSION=	0.1.1
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://www.enderunix.org/netustad/

MAINTAINER=	ozkan@enderunix.org
COMMENT=	A web based admin tool that manages network services

MAN8=		netustad.8 netustadpasswd.8
MAN5=		netustad.conf.5

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g'
	@${INSTALL_SCRIPT} ${FILESDIR}/netustad.sh.sample ${PREFIX}/etc/rc.d/

.include <bsd.port.mk>
