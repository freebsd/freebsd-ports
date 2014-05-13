# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rapidxml
PORTVERSION=	1.13
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast C++ library for parsing XML

LICENSE=	BSL

USES=		zip
NO_BUILD=	yes
PLIST_FILES=	include/rapidxml.hpp \
		include/rapidxml_iterators.hpp \
		include/rapidxml_print.hpp \
		include/rapidxml_utils.hpp
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.hpp ${STAGEDIR}${PREFIX}/include
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
