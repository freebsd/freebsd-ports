# New ports collection makefile for:	coolmail
# Version required:		1.3
# Date created:			Mon  6 Jul 12:00:06 CEST 1998
# Whom:				Udo Schweigert <Udo.Schweigert@mchp.siemens.de>
#
# $Id$
#

DISTNAME=	coolmail-1.3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=system/mail/biffs
EXTRACT_SUFX=	.tgz

MAINTAINER=	Udo.Schweigert@mchp.siemens.de

PATCH_STRIP=	-p1

MAN1=		coolmail.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/coolmail ${PREFIX}/bin/coolmail
	${INSTALL_MAN} ${WRKSRC}/coolmail.man ${PREFIX}/man/man1/coolmail.1

post-install:
	strip ${PREFIX}/bin/coolmail

.include <bsd.port.mk>
