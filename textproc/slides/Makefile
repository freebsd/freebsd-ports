# Created by: Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# $FreeBSD$

PORTNAME=	slides
PORTVERSION=	3.4.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/docbook/${PORTNAME}/${PORTVERSION}
DISTNAME=	docbook-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Doctype and stylesheets for making slides

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	docbook-xml>0:textproc/docbook-xml \
		docbook-xsl>0:textproc/docbook-xsl \
		xmlcatmgr:textproc/xmlcatmgr

NO_ARCH=	yes
NO_BUILD=	yes

USES=		tar:bzip2

OPTIONS_DEFINE=	DOCS

INSTDIR=	share/xsl/${PORTNAME}
PINSTDIR=	${PREFIX}/${INSTDIR}
COPYDIRS=	browser graphics schema xsl


do-install:
	@${MKDIR} ${STAGEDIR}${PINSTDIR}
.for i in VERSION catalog
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${PINSTDIR})
.endfor
.for i in ${COPYDIRS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${PINSTDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
