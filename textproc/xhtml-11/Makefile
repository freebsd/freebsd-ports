# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	xhtml
PORTVERSION=	1.1.${RECDATE}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/TR/2010/REC-xhtml11-${RECDATE}/
PKGNAMESUFFIX=	-11
DISTNAME=	xhtml11
DIST_SUBDIR=	${DISTNAME}-${RECDATE}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	W3C's XHTML 1.1 DTD

RUN_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr

USES=		tar:tgz

RECDATE=	20101123

WRKSRC=		${WRKDIR}/xhtml11-${RECDATE}
NO_BUILD=	yes

DTDDIR=		share/xml/${PORTNAME}/1.1/dtd
XSDDIR=		share/xml/${PORTNAME}/1.1/xsd

post-patch:
	${REINPLACE_CMD} -i '' 's|SGMLDECL "xml1.dcl"|-- SGMLDECL "xml1.dcl" --|g' \
		 ${WRKSRC}/DTD/xhtml11.cat

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DTDDIR}
	${INSTALL_DATA} ${WRKSRC}/DTD/* ${STAGEDIR}${PREFIX}/${DTDDIR}
	${INSTALL_DATA} ${FILESDIR}/catalog.xml ${STAGEDIR}${PREFIX}/${DTDDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${XSDDIR}
	${INSTALL_DATA} ${WRKSRC}/SCHEMA/* ${STAGEDIR}${PREFIX}/${XSDDIR}

.include <bsd.port.mk>
