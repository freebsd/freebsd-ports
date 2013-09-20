# Created by: David Thiel (lx@redundancy.redundancy.org)
# $FreeBSD$

PORTNAME=	sbd
PORTVERSION=	1.37
CATEGORIES=	net security
MASTER_SITES=	http://tigerteam.se/dl/sbd/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A netcat clone with more features and crypto

ALL_TARGET=	unix

PLIST_FILES=	bin/sbd
PORTDOCS=	README

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sbd ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
