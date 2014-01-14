# Created by: Aldert Nooitgedagt
# $FreeBSD$

PORTNAME=	tDOM
PORTVERSION=	0.8.3
CATEGORIES=	www
MASTER_SITES=	https://cloud.github.com/downloads/tDOM/tdom/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	High performance XML data processing with Tcl (ARGS for OpenACS)

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/unix
TDOMBASE=	${PREFIX}/lib/tdom${PORTVERSION}

OPTIONS_DEFINE=	DOCS

USES=		gmake tcl

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure

pre-configure:
	${RM} -f ${WRKSRC}/../generic/domalloc.?

USE_LDCONFIG=	${TDOMBASE}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

DOCS=		CHANGES LICENSE README README.AOL
HTMLDOCS=	category-index.html dom.html domDoc.html domNode.html \
		expat.html expatapi.html index.html keyword-index.html \
		tdomcmd.html tnc.html

post-build test:
	${SETENV} LANG=C ${MAKE} -C ${WRKSRC} test

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=--enable-threads --disable-tdomalloc \
		--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR} \
		--prefix=${PREFIX} --exec-prefix=${PREFIX}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
. for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/../${FILE} ${STAGEDIR}${DOCSDIR}/${FILE}
. endfor
. for FILE in ${HTMLDOCS}
	@${INSTALL_DATA} ${WRKSRC}/../doc/${FILE} ${STAGEDIR}${DOCSDIR}/html/${FILE}
. endfor
.endif

.include <bsd.port.mk>
