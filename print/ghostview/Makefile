# New ports collection makefile for:	ghostview
# Version required:	1.5
# Date created:		21 October 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.11 1998/10/20 01:48:36 steve Exp $
#

DISTNAME=	ghostview-1.5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	ghostview

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=	yes
MAN1=		ghostview.1

post-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
