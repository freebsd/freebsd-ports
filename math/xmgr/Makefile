# New ports collection makefile for:	xmgr
# Version required:	3.01pl8
# Date created:		So   2 Mär 1997 12:11:43 MET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.3 1998/04/30 08:35:42 tg Exp $
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

pre-extract:
	@$(ECHO_MSG) "Xinside Motif ? Then put this into /etc/make.conf:"
	@$(ECHO_MSG) "    MOTIFLIB=-L\${X11BASE}/lib -lXm -lXintl"

post-install:		
	@( cd ${X11BASE}/bin; ln -sf xmgr grbatch )

.include <bsd.port.mk>
