# Created by: David Thiel (lx@redundancy.redundancy.org)
# $FreeBSD$

PORTNAME=	glFlow
PORTVERSION=	0.1.4
PORTEPOCH=	1
CATEGORIES=	net security
MASTER_SITES=	SF
DISTNAME=	glFlow-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A NetFlow tool for detecting DoS attacks

PLIST_FILES=	bin/glflow
PORTDOCS=	README
WRKSRC=		${WRKDIR}/${PORTNAME}-0.1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-debug --with-hash=md4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glflow ${STAGEDIR}${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
