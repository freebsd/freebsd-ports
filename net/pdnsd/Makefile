# New ports collection makefile for:	pdnsd
# Date Created:				27 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	pdnsd
PORTVERSION=	1.1.7a
CATEGORIES=	net
MASTER_SITES=	http://home.t-online.de/home/Moestl/

MAINTAINER=	roman@xpert.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cachedir=${PDNSDB}

MAN8=		pdnsd-ctl.8

PDNSDB=		/var/db/pdnsd

post-install:
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/pdnsd.sh > ${PREFIX}/etc/rc.d/pdnsd.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/pdnsd.sh
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
