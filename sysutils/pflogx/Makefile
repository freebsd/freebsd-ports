# Created by: clsung
# $FreeBSD$

PORTNAME=	pflogx
PORTVERSION=	0.86
CATEGORIES=	sysutils
MASTER_SITES=	http://akldev.free.fr/pflogx/releases/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple tool to export pf (packet filter) logs to XML files

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_sparc64=	cannot compile: error in C++ code

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	EXPAT DOCS EXAMPLES

EXPAT_DESC=		Ability to merge new events (require expat)
EXPAT_LIB_DEPENDS=	libexpat.so:textproc/expat2
EXPAT_MAKE_ARGS=	-DWITH_EXPAT \
			EXPAT_INCLUDEDIR=${LOCALBASE}/include \
			EXPAT_LIBDIR=${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pflogx ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dtd/* ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xsl/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
