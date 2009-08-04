# New ports collection makefile for:	balance
# Date created:				Wed 6 Dec 2000
# Whom:					Joseph Scott <joseph@randomnetworks.com>
#
# $FreeBSD$
#

PORTNAME=	balance
PORTVERSION=	3.42
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.inlab.de/ \
		${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	balance

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	Simple but powerful generic tcp proxy with round robin features

ALL_TARGET=	balance
USE_RC_SUBR=	balance.sh

MAN1=		balance.1

pre-build:
	@${REINPLACE_CMD} -e 's|^CFLAGS|CFLAGS?|' \
	-e 's|^CC|CC?|' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/balance ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/balance.1 ${PREFIX}/man/man1
	@${MKDIR} /var/run/balance

.include <bsd.port.mk>
