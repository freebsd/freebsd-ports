# New ports collection makefile for:	pv
# Date created:		04 May 2004
# Whom:			Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	pv
PORTVERSION=	0.9.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pipeviewer

MAINTAINER=	daniel@roe.ch
COMMENT=	A pipe throughput monitor

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pv
MAN1=		pv.1
INFO=		pv
PORTDOCS=	README NEWS TODO manual.html

post-patch:
	@${CP} ${WRKSRC}/README ${WRKSRC}/doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/quickref.1 ${PREFIX}/man/man1/pv.1
	${INSTALL_DATA} ${WRKSRC}/doc/pv.info ${PREFIX}/${INFO_PATH}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
