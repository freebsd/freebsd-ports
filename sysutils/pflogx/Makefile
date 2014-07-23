# Created by: clsung
# $FreeBSD$

PORTNAME=	pflogx
PORTVERSION=	0.86
CATEGORIES=	sysutils
MASTER_SITES=	http://akldev.free.fr/pflogx/releases/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Simple tool to export pf (packet filter) logs to XML files

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	EXPAT DOCS
EXPAT_DESC=	Ability to merge new events (require expat)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXPAT}
LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2
MAKE_ARGS+=	-DWITH_EXPAT \
		EXPAT_INCLUDEDIR=${LOCALBASE}/include \
		EXPAT_LIBDIR=${LOCALBASE}/lib
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pflogx ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dtd/* ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xsl/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
