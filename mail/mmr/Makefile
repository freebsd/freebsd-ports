# New ports collection makefile for:	mmr
# Version required:			1.5.1
# Date created:				23 October 1997
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=		mmr-1.5.1
CATEGORIES=		mail
MASTER_SITE_SUBDIR=	system/mail/mua
MASTER_SITES=		${MASTER_SITE_SUNSITE}

MAINTAINER=		andy@icc.surw.chel.su

ALL_TARGET=		mmr

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/mmr ${PREFIX}/bin

.include <bsd.port.mk>
