# Created by: kuriyama
# $FreeBSD$

PORTNAME=	xhtml
PORTVERSION=	1.0.20020801
PORTREVISION=	5
CATEGORIES=	textproc
#MASTER_SITES=	http://www.w3.org/TR/xhtml1/
MASTER_SITES=	LOCAL/kuriyama
DISTNAME=	xhtml1-20020801

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	W3C's XHTML DTD

RUN_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr

USES=		zip
NO_MTREE=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}/xhtml1-20020801
SUB_FILES=	catalog.xml
SUB_LIST+=	DTDDIR="${DTDDIR}"

INSTDIR=	${PREFIX}/share/xml
DTDDIR=		${INSTDIR}/dtd/xhtml
DTDFILES=	xhtml-lat1.ent xhtml-special.ent xhtml-symbol.ent \
		xhtml.soc xhtml1-frameset.dtd xhtml1-strict.dtd \
		xhtml1-transitional.dtd xhtml1.dcl ${WRKDIR}/catalog.xml

pre-su-install:
	@[ -d ${STAGEDIR}${DTDDIR}	 ] || ${MKDIR} ${STAGEDIR}${DTDDIR}

do-install:
	@(cd ${WRKSRC}/DTD; ${INSTALL_DATA} ${DTDFILES} ${STAGEDIR}${DTDDIR})
	${SED} -e 's|SGMLDECL.*||' ${WRKSRC}/DTD/xhtml.soc > ${STAGEDIR}${DTDDIR}/xhtml-dcl.soc

.include <bsd.port.mk>
