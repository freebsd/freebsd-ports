# New ports collection makefile for:	transfig
# Version required:	3.2.1
# Date created:		9 August 1996
# Whom:			chuckr@freebsd.org
#
# $Id: Makefile,v 1.22 1998/10/03 21:34:09 steve Exp $
#

DISTNAME=	transfig.3.2.1
PKGNAME=	transfig-3.2.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_XCONTRIB} ${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	applications/drawing_tools/transfig
DISTFILES=	transfig.3.2.1.tar.gz transfig.3.2.ja_JP.EUC.ps.gz

MAINTAINER=	chuckr@freebsd.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	ppmtogif:${PORTSDIR}/graphics/netpbm

USE_IMAKE=	yes
EXTRACT_ONLY=	transfig.3.2.1.tar.gz
MAN1=		fig2dev.1 fig2ps2tex.1 pic2tpic.1 transfig.1

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/fig2dev
	@${GZCAT} ${DISTDIR}/transfig.3.2.ja_JP.EUC.ps.gz \
		> ${PREFIX}/lib/X11/fig2dev/ja_JP.EUC.ps

.include <bsd.port.mk>
