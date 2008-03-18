# New ports collection makefile for: HPACUCLI
# Date created: 28 October 2007
# Whom: SriSaiGanesh
#
# $FreeBSD$
#

PORTNAME=		hpacucli
PORTVERSION=		7.50
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
DISTNAME=		hpacucli-${PORTVERSION}

MAINTAINER=		v.sri.sai.ganesh@hp.com
COMMENT=		HP ARRAY CONFIGURATION UTILITY for Smart Array RAID cards

USE_BZIP2=		yes
NO_BUILD=		yes
IA32_BINARY_PORT=	yes

LIB_DEPENDS+=		c.4:${PORTSDIR}/misc/compat4x
LIB_DEPENDS+=		c.5:${PORTSDIR}/misc/compat5x

APP_PREFIX=		lib/compaq/hpacucli
USE_LDCONFIG=		${PREFIX}/${APP_PREFIX}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/${PORTNAME}

do-install:
	@${MKDIR} -m 0755 -p ${PREFIX}/${APP_PREFIX}
	@${CP} ${WRKSRC}/lib* ${PREFIX}/${APP_PREFIX}/
	@${INSTALL_PROGRAM} ${WRKSRC}/.${PORTNAME} ${PREFIX}/libexec/
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/

.include <bsd.port.mk>
