# New ports collection makefile for:	mmr
# Version required:			1.5.1
# Date created:				23 October 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1997/11/04 04:45:01 asami Exp $
#

DISTNAME=		mmr-1.5.1
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/mail/mua

MAINTAINER=		andy@icc.surw.chel.su

ALL_TARGET=		mmr

BROKEN_ELF=	md5/libmd5.a

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/mmr ${PREFIX}/bin

.include <bsd.port.mk>
