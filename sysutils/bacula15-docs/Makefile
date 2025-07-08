PORTNAME=	bacula
PORTVERSION=	15.0.3
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMESUFFIX=	15-docs
DISTNAME=	${PORTNAME}-docs-${PORTVERSION}

CONFLICTS=	bacula11-docs bacula13-docs bacula9-docs

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Bacula document set
WWW=		https://www.bacula.org/

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
