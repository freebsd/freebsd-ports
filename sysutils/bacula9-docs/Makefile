# Created by: Dan Langille <dan@langille.org>
# $FreeBSD$

PORTNAME=	bacula
PORTVERSION=	9.6.5
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMESUFFIX=	9-docs
DISTNAME=	${PORTNAME}-docs-${PORTVERSION}

CONFLICTS=	bacula-* bacula5-*

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Bacula document set

USES=		tar:bz2
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	*.pdf

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${FIND} ${WRKSRC}/manuals/en \
		-name "*.pdf" -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/ \;

.include <bsd.port.mk>
