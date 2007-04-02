# New ports collection makefile for:	miniupnpd
# Date created:		22 March 2007
# Whom:			Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	miniupnpd
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://miniupnp.tuxfamily.org/files/ \
		http://miniupnp.free.fr/files/
DISTNAME=	${PORTNAME}-1.0-RC4

MAINTAINER=	darius@dons.net.au
COMMENT=	A UPnP IGD implementation which uses pf

USE_GMAKE=	yes

SUB_FILES=	miniupnpd.conf.sample
SUB_LIST=	UUID=${UUID}

UUID!=		uuidgen

USE_RC_SUBR=	miniupnpd.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/miniupnpd ${PREFIX}/sbin/miniupnpd
	@${INSTALL_DATA} ${WRKDIR}/miniupnpd.conf.sample ${PREFIX}/etc/miniupnpd.conf.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
