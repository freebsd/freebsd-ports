# New ports collection makefile for:	sarah
# Version required:	0.1b
# Date created:		10 Jan 2000
# Whom:			Matthew Pounsett <mattp@conundrum.com>
#
# $FreeBSD$
#

DISTNAME=		sarah-0.1b
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.conundrum.com/pub/sarah/

MAINTAINER=		mattp@conundrum.com

MAN1=			sarah.1
USE_PERL5=		yes
NO_BUILD=		yes

do-install:
	cd ${WRKSRC} && \
		${INSTALL_SCRIPT} sarah ${PREFIX}/bin
	cd ${WRKSRC} && \
		${INSTALL_DATA} sarah.conf.sample ${PREFIX}/etc
	cd ${WRKSRC} && \
		${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
