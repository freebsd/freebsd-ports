# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xmailbox
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	XCONTRIB/applications

MAINTAINER=	freebsd@skysmurf.nl
COMMENT=	Mailbox checker with sound and animation for X Window System

USES=		imake
USE_XORG=	xaw

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/XMailbox.ad

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xmailbox
	${INSTALL_DATA} ${WRKSRC}/dingdong.au ${STAGEDIR}${PREFIX}/share/xmailbox
	${INSTALL_DATA} ${WRKSRC}/ugotmail.au ${STAGEDIR}${PREFIX}/share/xmailbox
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/xmailbox
	${INSTALL_DATA} ${WRKSRC}/DISCLAIMER ${STAGEDIR}${PREFIX}/share/doc/xmailbox
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/share/doc/xmailbox
.endif

.include <bsd.port.mk>
