# New ports collection makefile for:	ghostview
# Version required:	1.5
# Date created:		21 October 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.9 1997/01/14 09:11:49 asami Exp $
#

DISTNAME=	ghostview-1.5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=	yes

post-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
