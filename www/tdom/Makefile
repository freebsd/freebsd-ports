# Created by: Aldert Nooitgedagt
# $FreeBSD$

PORTNAME=	tDOM
PORTVERSION=	0.8.3
CATEGORIES=	www
MASTER_SITES=	GHC http://mirrors.rit.edu/zi/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	High performance XML data processing with Tcl (ARGS for OpenACS)

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
TDOMBASE=	${PREFIX}/lib/tdom${PORTVERSION}

OPTIONS_DEFINE=	DOCS

USES=		gmake tar:tgz tcl:tea
USE_GITHUB=	yes
GH_PROJECT=	tdom

pre-configure:
	${RM} -f ${WRKSRC}/generic/domalloc.?

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

DOCS=		CHANGES LICENSE README README.AOL
HTMLDOCS=	category-index.html dom.html domDoc.html domNode.html \
		expat.html expatapi.html index.html keyword-index.html \
		tdomcmd.html tnc.html

post-build test:
	${SETENV} LANG=C ${MAKE} -C ${WRKSRC} test

CONFIGURE_ARGS+=--enable-threads --disable-tdomalloc

post-install:
	${CHMOD} 755 ${STAGEDIR}${TDOMBASE}
	${CHMOD} 644 ${STAGEDIR}${TDOMBASE}/*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}/${FILE}
.endfor
.for FILE in ${HTMLDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${STAGEDIR}${DOCSDIR}/html/${FILE}
.endfor

.include <bsd.port.mk>
