# ex:ts=8
# New ports collection makefile for:	gv
# Version required:	gv-3.5.8
# Date created:		16 Apr 1996
# Whom:			tg@freebsd.org
#
# $Id: Makefile,v 1.19 1998/10/20 01:48:37 steve Exp $
#

DISTNAME=	gv-3.5.8
CATEGORIES=	print
MASTER_SITES=	ftp://thep.physik.uni-mainz.de/pub/gv/unix/  \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/ghostscript/gnu/gv/unix

MAINTAINER=	obrien@freebsd.org

LIB_DEPENDS=	Xaw3d.6:${PORTSDIR}/x11-toolkits/Xaw3d

USE_IMAKE=	yes
MAN1=		gv.1

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}; ${MAKE} install.doc)
.endif
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
