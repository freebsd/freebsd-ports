# $FreeBSD$

PORTNAME=	bacula
PORTVERSION=	11.0.1
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMESUFFIX=	11-docs
DISTNAME=	${PORTNAME}-docs-${PORTVERSION}

CONFLICTS=	bacula9-*

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
