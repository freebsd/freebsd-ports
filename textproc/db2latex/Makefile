# Created by: ijliao
# $FreeBSD$

PORTNAME=	db2latex
PORTVERSION=	0.8p1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.8pre1
DISTNAME=	${PORTNAME}-xsl-${PORTVERSION:S/p/pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DocBook to LaTeX XSL stylesheets

RUN_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xml/docbook/4.2/docbook.cat:${PORTSDIR}/textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/VERSION:${PORTSDIR}/textproc/docbook-xsl

NO_BUILD=	yes

PORTDOCS=	*

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/xsl ${STAGEDIR}${DATADIR}
	@${FIND} ${STAGEDIR}${DATADIR} ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
