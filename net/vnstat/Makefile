# New ports collection makefile for:	vnstat
# Date created:		February 17, 2008
# Whom:		Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	vnstat
PORTVERSION=	1.6
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://humdi.net/vnstat/ \
		http://mirror.mcx2.org/ \
		http://ftp.uwsg.indiana.edu/FreeBSD/distfiles/ \
		ftp://ftp.jpix.ad.jp/pub/FreeBSD/ports/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}_bsd

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A console-based network traffic monitor

MAN1=	vnstat.1
MANCOMPRESSED=	yes
PORTDOCS=	README INSTALL vnstat-cron
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
SUB_FILES=	pkg-message

post-extract:
	@cd ${WRKSRC} && ${CP} cron/vnstat vnstat-cron
	@${REINPLACE_CMD} -e 's|/usr/bin|/usr/local/bin|g' \
		-e 's|ls /var/lib|ls -l /var/db|g' ${WRKSRC}/vnstat-cron

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
