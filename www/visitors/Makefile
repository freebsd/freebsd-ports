# Created by: Florent Thoumie <flz@xbsd.org>
# $FreeBSD$

PORTNAME=	visitors
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.hping.org/visitors/
DISTNAME=	${PORTNAME}-0.7

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Very fast and easy to use web log analyzer

WRKSRC=		${WRKDIR}/${PORTNAME}_0.7

PLIST_FILES=	bin/visitors
PORTDOCS=	doc.html

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/visitors ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
