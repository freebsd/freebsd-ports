# New ports collection makefile for:	xmailbox
# Version required:			2.5
# Date created:				23 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/07/04 19:42:45 steve Exp $
#

DISTNAME=		xmailbox-2.5
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=		andy@icc.surw.chel.su

LIB_DEPENDS=		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=		yes

MAN1=			xmailbox.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xmailbox ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/xmailbox.man ${PREFIX}/man/man1/xmailbox.1
	@ ${INSTALL_DATA} ${WRKSRC}/XMailbox.ad ${PREFIX}/lib/X11/app-defaults/XMailbox
	@ ${MKDIR} ${PREFIX}/share/xmailbox
	@ ${INSTALL_DATA} ${WRKSRC}/dingdong.au ${PREFIX}/share/xmailbox
	@ ${INSTALL_DATA} ${WRKSRC}/ugotmail.au ${PREFIX}/share/xmailbox
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/xmailbox
	@ ${INSTALL_DATA} ${WRKSRC}/DISCLAIMER ${PREFIX}/share/doc/xmailbox
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xmailbox
.endif

.include <bsd.port.mk>
