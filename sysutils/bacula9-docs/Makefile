PORTNAME=	bacula
PORTVERSION=	9.6.7
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMESUFFIX=	9-docs
DISTNAME=	${PORTNAME}-docs-${PORTVERSION}

CONFLICTS=	bacula15-docs bacula13-docs bacula11-docs 

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Bacula document set
WWW=		https://www.bacula.org/

DEPRECATED=	Unsupported. Please migrate to bacula15-server
EXPIRATION_DATE=	2024-09-30

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
