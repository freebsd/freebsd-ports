# New ports collection makefile for:	pdnsd
# Date Created:				27 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	pdnsd
PORTVERSION=	1.1.0b2
CATEGORIES=	net
MASTER_SITES=	http://home.t-online.de/home/Moestl/

MAINTAINER=	roman@xpert.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cachedir=${PDNSDB}

PDNSDB=		/var/db/pdnsd

post-install:
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${INSTALL} ${COPY} -m 744 -o root ${FILESDIR}/pdnsd.sh ${PREFIX}/etc/rc.d/pdnsd.sh
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
