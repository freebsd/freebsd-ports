# New ports collection makefile for:	xmgr
# Version required:	3.01pl8
# Date created:		So   2 Mär 1997 12:11:43 MET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.2 1998/04/30 08:31:47 tg Exp $
#

DISTNAME=	xmgr-3.01
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	andreas@FreeBSD.ORG

WRKSRC=			${WRKDIR}/xmgr-3.01pl8/src
USE_IMAKE=		yes
REQUIRES_MOTIF=		yes
NO_INSTALL_MANPAGES=	yes

post-install:		
	@( cd ${X11BASE}/bin; ln -sf xmgr grbatch )

.include <bsd.port.mk>
