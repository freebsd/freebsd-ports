# New ports collection makefile for:	xmailbox
# Date created:				23 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		xmailbox
PORTVERSION= 		2.5
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=		ports@FreeBSD.org

LIB_DEPENDS=		Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=		yes
MAN1=			xmailbox.1
MANCOMPRESSED=		no

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
