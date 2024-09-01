PORTNAME=	bacula
PORTVERSION=	11.0.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMESUFFIX=	11-docs
DISTNAME=	${PORTNAME}-docs-${PORTVERSION}

CONFLICTS=	bacula15-docs bacula13-docs bacula9-docs

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
