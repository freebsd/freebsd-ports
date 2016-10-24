# Created by: Dan Langille <dan@langille.org>
# $FreeBSD$

PORTNAME=	bacula-docs
PORTVERSION=	7.4.4
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Bacula document set

USES=		tar:bz2
NO_BUILD=	yes

PORTDOCS=	*.pdf

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${FIND} ${WRKSRC}/manuals/en \
		-name "*.pdf" -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/ \;

.include <bsd.port.mk>
