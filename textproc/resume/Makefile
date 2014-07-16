# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	resume
PORTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/xml${PORTNAME}/xml${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML Resume library

USE_JAVA=	yes
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} -e 's|\.\./\.\./css|css|' ${WRKSRC}/xsl/params.xsl
	${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xml/${PORTNAME}
	${CP} -R ${WRKSRC}/dtd/* ${STAGEDIR}${PREFIX}/share/xml/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xsl/${PORTNAME}
	${CP} -R ${WRKSRC}/xsl/* ${STAGEDIR}${PREFIX}/share/xsl/${PORTNAME}
	${CP} -R ${WRKSRC}/css ${STAGEDIR}${PREFIX}/share/xsl/${PORTNAME}/format
	${INSTALL_DATA} ${WRKSRC}/java/*.jar ${STAGEDIR}${JAVAJARDIR}

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
	${SED} -e "s|%%PREFIX%%|${PREFIX}|g" pkg-message >${PKGMESSAGE}

.include <bsd.port.mk>
