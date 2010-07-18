# New ports collection makefile for:	miniupnpd
# Date created:		22 March 2007
# Whom:			Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	miniupnpd
PORTVERSION=	1.4.20100511
CATEGORIES=	net
MASTER_SITES=	http://miniupnp.tuxfamily.org/files/ \
		http://miniupnp.free.fr/files/

MAINTAINER=	squat@squat.no
COMMENT=	A UPnP IGD implementation which uses pf/ipf

SUB_FILES=	miniupnpd.conf.sample
SUB_LIST=	UUID=${UUID}

UUID!=		uuidgen
FWNAME?=	pf
PLIST_FILES=	etc/miniupnpd.conf.sample sbin/miniupnpd

MAN8=		miniupnpd.8

USE_RC_SUBR=	miniupnpd.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/miniupnpd ${PREFIX}/sbin/miniupnpd
	@${INSTALL_DATA} ${WRKDIR}/miniupnpd.conf.sample ${PREFIX}/etc/miniupnpd.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/miniupnpd.1 ${PREFIX}/man/man8/miniupnpd.8
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
