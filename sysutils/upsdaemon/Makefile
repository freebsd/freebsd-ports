# Created by: Ederson de Moura <ederbs@ederbs.org>
# $FreeBSD$

PORTNAME=	upsdaemon
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ederbs.org/pub/ \
		ftp://ederbs.org/pub/

MAINTAINER=	freebsduser@paradisegreen.co.uk
COMMENT=	Simple APC UPS Daemon

MAN8=		upsdaemon.8
MANCOMPRESSED=	no

USE_RC_SUBR=	upsdaemon

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
