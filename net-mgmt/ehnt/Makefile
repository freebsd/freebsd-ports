PORTNAME=	ehnt
PORTVERSION=	0.3
PORTREVISION=	8
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	marck@FreeBSD.org
COMMENT=	Simple Cisco NetFlow data collector

PLIST_FILES=	bin/ehnt etc/rc.d/ehntserv.sh.sample \
		man/man1/ehnt.1.gz man/man8/ehntserv.8.gz \
		sbin/ehntserv share/ehnt/asnc.txt

PORTDOCS=	README
STPREFIX=	${STAGEDIR}${PREFIX}

OPTIONS_DEFINE=	DOCS

post-extract:
	${TOUCH} ${WRKSRC}/asnc.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ehnt ${STPREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/ehntserv ${STPREFIX}/sbin/
	${INSTALL_SCRIPT} ${FILESDIR}/ehntserv.sh.sample ${STPREFIX}/etc/rc.d/
	${INSTALL_MAN} ${WRKSRC}/ehnt.1 ${STPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/ehntserv.8 ${STPREFIX}/man/man8/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/asnc.txt ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
