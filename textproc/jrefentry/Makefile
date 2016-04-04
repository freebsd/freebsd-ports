# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	jrefentry
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/docbook/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DocBook XML JRefEntry DTD

RUN_DEPENDS=	docbook-xml>0:textproc/docbook-xml

NO_BUILD=	yes

XMLDIR=		${PREFIX}/share/xml/docbook/${PORTNAME}

PORTDOCS=	README.html
PORTEXAMPLES=	jtest.xml

OPTIONS_DEFINE=	EXAMPLES DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${XMLDIR}
	${INSTALL_DATA} ${WRKSRC}/jrefentry.dtd ${STAGEDIR}${XMLDIR}
	${ECHO_CMD} 'PUBLIC "-//Norman Walsh//DTD JRefEntry V1.1//EN" "jrefentry.dtd"' \
		>${STAGEDIR}${XMLDIR}/catalog
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/jtest.xml ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
