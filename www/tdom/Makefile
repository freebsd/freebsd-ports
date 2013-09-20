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

USE_TCL=	84+

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure

NO_STAGE=	yes
pre-configure:
	${RM} -f ${WRKSRC}/../generic/domalloc.?

USE_LDCONFIG=	${TDOMBASE}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MANN=		dom.n domDoc.n domNode.n expat.n expatapi.n tdomcmd.n tnc.n
MANCOMPRESSED=	no

DOCS=		CHANGES LICENSE README README.AOL
HTMLDOCS=	category-index.html dom.html domDoc.html domNode.html \
		expat.html expatapi.html index.html keyword-index.html \
		tdomcmd.html tnc.html

post-build test:
	${SETENV} LANG=C ${MAKE} -C ${WRKSRC} test

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--enable-threads --disable-tdomalloc \
		--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR} --prefix=${PREFIX}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
. for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/../${FILE} ${DOCSDIR}/${FILE}
. endfor
. for FILE in ${HTMLDOCS}
	@${INSTALL_DATA} ${WRKSRC}/../doc/${FILE} ${DOCSDIR}/html/${FILE}
. endfor
.endif

.include <bsd.port.post.mk>
