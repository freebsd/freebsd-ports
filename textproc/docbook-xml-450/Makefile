# Created by: alepulver
# $FreeBSD$

PORTNAME=	docbook-xml
PORTVERSION=	4.5
PORTREVISION=	1

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	DocBook/XML DTD V4.5, designed for technical documentation

NO_ISOCAT=	yes
XML_DTD=	yes
HAS_MANUAL_CATALOG_FILE=	yes
MANUAL_DOCS=	yes

DTD_SUBDIR=	${PORTNAME:S/-xml//}

PORTDOCS=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/ent
.for f in ChangeLog README ent/README
	${MV} ${STAGEDIR}${PREFIX}/${DTDDIR}/${f} ${STAGEDIR}${DOCSDIR}/${f}
.endfor

.include "../../textproc/docbook/bsd.docbook.mk"
.include <bsd.port.mk>
