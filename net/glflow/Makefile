# Ports collection makefile for:  glflow
# Date created:			  2004-07-12
# Whom:				  David Thiel (lx@redundancy.redundancy.org)
#
# $FreeBSD$
#

PORTNAME=	glflow
PORTVERSION=	0.1.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net security
MASTER_SITES=	http://night.rdslink.ro/dudu/glflow/
DISTNAME=	glFlow-${PORTVERSION}

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	A NetFlow tool for detecting DoS attacks

PLIST_FILES=	bin/glflow
PORTDOCS=	README
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-debug --with-hash=md4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glflow ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
