# New ports collection makefile for:	ehnt
# Date created:		2 August 2001
# Whom:			marck@rinet.ru
#
# $FreeBSD$
#

PORTNAME=	ehnt
PORTVERSION=	0.3
PORTREVISION=	8
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	marck@FreeBSD.org
COMMENT=	A simple Cisco NetFlow data collector

PLIST_FILES=	bin/ehnt etc/rc.d/ehntserv.sh.sample \
		sbin/ehntserv share/ehnt/asnc.txt
PLIST_DIRS+=	share/ehnt

PORTDOCS=	README

MAN1=		ehnt.1
MAN8=		ehntserv.8

post-extract:
	${TOUCH} ${WRKSRC}/asnc.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ehnt ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/ehntserv ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${FILESDIR}/ehntserv.sh.sample ${PREFIX}/etc/rc.d/
	${INSTALL_MAN} ${WRKSRC}/ehnt.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/ehntserv.8 ${PREFIX}/man/man8/
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/asnc.txt ${DATADIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
