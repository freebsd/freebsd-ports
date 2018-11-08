# Created by: Dan Langille <dan@langille.org>
# $FreeBSD$

PORTNAME=	bacula-docs
PORTVERSION=	7.4.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Bacula document set

DEPRECATED=	Unsupported. Please migrate to bacula9-docs
EXPIRATION_DATE=	2019-03-01

USES=		tar:bz2
NO_BUILD=	yes

PORTDOCS=	*.pdf

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${FIND} ${WRKSRC}/manuals/en \
		-name "*.pdf" -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/ \;

.include <bsd.port.mk>
