# Created by: Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# $FreeBSD$

PORTNAME=	website
PORTVERSION=	2.6.0
CATEGORIES=	textproc www
MASTER_SITES=	SF/docbook/${PORTNAME}/${PORTVERSION}
DISTNAME=	docbook-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Doctype and stylesheets for making websites

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl

NO_ARCH=	yes
NO_BUILD=	yes

USES=		tar:bzip2

OPTIONS_DEFINE=	EXAMPLES

INSTDIR=	share/xsl/website
PINSTDIR=	${PREFIX}/${INSTDIR}
COPYDIRS=	extensions schema xsl

do-install:
	@${MKDIR} ${STAGEDIR}${PINSTDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${STAGEDIR}/${PINSTDIR}
	${INSTALL_DATA} ${WRKSRC}/catalog ${STAGEDIR}/${PINSTDIR}/catalog.xml
.for i in ${COPYDIRS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${PINSTDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
