# Created by: David O'Brien <obrien@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lprps
PORTVERSION=	2.5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.jclark.com/pub/lprps/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	PostScript printer filter supporting a bidirectional serial channel

LIB_DEPENDS=	paper:${PORTSDIR}/print/libpaper

PORTDOCS=	INSTALL
MAN1=		psrev.1 textps.1
MAN8=		lprps.8 psif.8 psof.8

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} textps psrev ${PREFIX}/bin && \
		${INSTALL_PROGRAM} psif lprps psof ${PREFIX}/libexec && \
		${INSTALL_SCRIPT} psif-text psif-ps ${PREFIX}/libexec && \
		${INSTALL_DATA} banner.ps ${DATADIR} && \
		${INSTALL_MAN} textps.n ${PREFIX}/man/man1/textps.1 && \
		${INSTALL_MAN} psrev.n ${PREFIX}/man/man1/psrev.1 && \
		${INSTALL_MAN} lprps.n ${PREFIX}/man/man8/lprps.8 && \
		${INSTALL_MAN} psif.n ${PREFIX}/man/man8/psif.8 && \
		${INSTALL_MAN} psof.n ${PREFIX}/man/man8/psof.8

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
