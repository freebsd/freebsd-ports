# Ports collection makefile for:  glflow
# Date created:			  2004-07-12
# Whom:				  David Thiel (lx@redundancy.redundancy.org)
#
# $FreeBSD$
#

PORTNAME=	glflow
PORTVERSION=	0.0.4
CATEGORIES=	net security
MASTER_SITES=	http://night.rdslink.ro/dudu/glflow/
DISTNAME=	glFlow-${PORTVERSION}

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	A NetFlow tool for detecting DoS attacks

PLIST_FILES=	bin/glflow
PORTDOCS=	README
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glflow ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
