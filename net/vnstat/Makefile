# New ports collection makefile for:	vnstat
# Date created:		February 17, 2008
# Whom:		Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	vnstat
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://humdi.net/vnstat/ \
		http://mcx2.org/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}_bsd

MAINTAINER=	adox@mcx2.org
COMMENT=	A console-based network traffic monitor

MAN1=	vnstat.1
MANCOMPRESSED=	yes
PORTDOCS=	README INSTALL vnstat-cron
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
SUB_FILES=	pkg-message

post-extract:
	@cd ${WRKSRC} && ${CP} cron/vnstat vnstat-cron
	@${REINPLACE_CMD} -e 's|/usr/bin|/usr/local/bin|g' \
		-e 's|/var/lib|/var/db|g' ${WRKSRC}/vnstat-cron

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.mk>
