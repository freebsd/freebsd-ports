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

INSTDIR=	${PREFIX}/share/xsl/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${WRKSRC}/catalog ${STAGEDIR}${INSTDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "browser graphics schema xsl" ${STAGEDIR}${INSTDIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
