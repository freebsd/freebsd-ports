# New ports collection makefile for:	gv
# Version required:	gv-3.5.8
# Date created:		16 Apr 1996
# Whom:			tg@freebsd.org
#
# $Id: Makefile,v 1.15 1997/06/23 07:35:15 tg Exp $
#

DISTNAME=	gv-3.5.8
CATEGORIES=	print
MASTER_SITES=	ftp://thep.physik.uni-mainz.de/pub/gv/unix/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	Xaw3d\\.6\\.:${PORTSDIR}/x11/Xaw3d

USE_IMAKE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}; ${MAKE} install.doc)
.endif
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
