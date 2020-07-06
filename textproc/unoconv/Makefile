# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unoconv
PORTVERSION=	0.7
CATEGORIES=	textproc python
MASTER_SITES=	http://dag.wieers.com/home-made/${PORTNAME}/ \
		SF/nemysisfreebsdp/textproc/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert any document from and to any LibreOffice supported format

LICENSE=	GPLv2

RUN_DEPENDS=	xsltproc:textproc/libxslt

USES=		python
NO_BUILD=	yes

PORTDOCS=	*

DOC_FILES=	AUTHORS ChangeLog README.adoc
DOC_FILES2=	errcode.adoc filters.adoc formats.adoc \
		office-installations.adoc selinux.adoc unoconv.1.adoc

OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME} pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|' \
		${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}/tests/
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
.for f in *.odt *.csv
	@(cd ${WRKSRC}/tests && ${INSTALL_DATA} ${f} ${STAGEDIR}${DATADIR}/tests)
.endfor
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
