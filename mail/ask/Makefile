# Created by: Marcelo Araujo <araujobsd@gmail.com>
# $FreeBSD$

PORTNAME=	ask
PORTVERSION=	2.5.3
CATEGORIES=	mail
MASTER_SITES=	SF/a-s-k/${PORTNAME}-beta/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anti Spam Killer content filtering

USES=		python
NO_BUILD=	yes

ASKLIBDIR=	${PREFIX}/lib/${PORTNAME}
BINS=		askfilter asksetup utils/asksenders
SUB_FILES=	pkg-message
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	@${REINPLACE_CMD} -E \
		-e "s,/usr/share/ask/templates,${EXAMPLESDIR},g" \
		-e "s,/usr/lib/ask,${ASKLIBDIR},g" \
		-e "s,^(#!)/usr/bin/python,\1${PYTHON_CMD}," \
		${BINS:S,^,${WRKSRC}/,} ${WRKSRC}/*.py

do-install:
	@${MKDIR} ${STAGEDIR}${ASKLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/*.py ${STAGEDIR}${ASKLIBDIR}
	${INSTALL_SCRIPT} ${BINS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/templates/* ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/docs && ${INSTALL_MAN} askfilter.1 asksetup.1 \
		asksenders.1 ${STAGEDIR}${PREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.[!1]* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
