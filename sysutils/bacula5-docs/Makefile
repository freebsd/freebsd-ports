# Created by: Dan Langille <dan@langille.org>
# $FreeBSD$

PORTNAME=	bacula
PORTVERSION=	5.2.12
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMESUFFIX=	5-docs
DISTNAME=	${PORTNAME}-docs-${PORTVERSION}

CONFLICTS=	bacula-*

MAINTAINER=	dan@langille.org
COMMENT=	Bacula document set

USES=		tar:bz2
NO_BUILD=	yes

PORTDOCS=	*.pdf

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${FIND} ${WRKSRC}/manuals/en \
		-name "*.pdf" -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/ \;

.include <bsd.port.mk>
