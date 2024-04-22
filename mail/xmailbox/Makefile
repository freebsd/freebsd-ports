PORTNAME=	xmailbox
PORTVERSION=	2.5
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	XCONTRIB/applications

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mailbox checker with sound and animation for X Window System

USES=		imake xorg
USE_XORG=	xaw

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/XMailbox.ad

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dingdong.au ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ugotmail.au ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DISCLAIMER ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
