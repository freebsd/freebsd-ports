# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=		xmailbox
PORTVERSION=		2.5
PORTREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Mailbox checker with sound and animation for X Window System

DEPRECATED=	Unmaintained since 2000
EXPIRATION_DATE=	2014-04-11
USES=		imake
USE_XORG=	xaw
MAN1=		xmailbox.1

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/XMailbox.ad

post-install:
	@${MKDIR} ${PREFIX}/share/xmailbox
	${INSTALL_DATA} ${WRKSRC}/dingdong.au ${PREFIX}/share/xmailbox
	${INSTALL_DATA} ${WRKSRC}/ugotmail.au ${PREFIX}/share/xmailbox
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${PREFIX}/share/doc/xmailbox
	${INSTALL_DATA} ${WRKSRC}/DISCLAIMER ${PREFIX}/share/doc/xmailbox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xmailbox
.endif

.include <bsd.port.mk>
