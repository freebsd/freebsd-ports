# Created by: Matt Peterson <matt@peterson.org>
# $FreeBSD$

PORTNAME=	sortu
PORTVERSION=	2.1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://256.com/sources/sortu/ \
		http://matt.peterson.org/FreeBSD/ports/
EXTRACT_SUFX=	.tgz

MAINTAINER=	matt@peterson.org
COMMENT=	Tool that combines sort and uniq functionality

BROKEN=		unfetchable

LICENSE=	ISCL

PORTDOCS=	*
PLIST_FILES=	bin/sortu

ALL_TARGET=	sortu

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sortu ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
