# New ports collection makefile for:	ytree
# Version required:	1.63
# Date created:		5 Jan 1998
# Whom:			Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/03/02 01:00:54 jseger Exp $
#

DISTNAME=		ytree-1.63
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file/managers

MAINTAINER=		andy@icc.surw.chel.su

ALL_TARGET=
MAN1=			ytree.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ytree ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/ytree.conf ${PREFIX}/etc/ytree.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/ytree.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
