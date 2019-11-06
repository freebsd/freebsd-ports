# Created by: Harry Newton
# $FreeBSD$

PORTNAME=	xmailwatcher
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.dcs.ed.ac.uk/home/gdmr/X11/
DISTNAME=	xmailwatcher

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mailbox checker which displays sender and subject lines of mails

PLIST_FILES=	bin/xmailwatcher man/man1/xmailwatcher.1.gz
USES=		imake xorg
USE_XORG=	ice sm x11 xaw xext xmu xpm xt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xmailwatcher

.include <bsd.port.mk>
