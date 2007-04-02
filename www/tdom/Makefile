# New ports collection makefile for:	tDOM
# Date created:				July 2005
# Whom:					Aldert Nooitgedagt
#
# $FreeBSD$
#

PORTNAME=	tDOM
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.tdom.org/files/

MAINTAINER=	martin@matuska.org
COMMENT=	High performance XML data processing with Tcl (ARGS for OpenACS)

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/unix
TDOMBASE=	${PREFIX}/lib/tdom${PORTVERSION}

USE_TCL=	84+
USE_TCL_THREADS=	yes

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure

USE_LDCONFIG=	${TDOMBASE}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MANN=		dom.n domDoc.n domNode.n expat.n expatapi.n tdomcmd.n tnc.n
MANCOMPRESSED=	no

DOCS=		CHANGES LICENSE README README.AOL
HTMLDOCS=	category-index.html dom.html domDoc.html domNode.html \
		expat.html expatapi.html index.html keyword-index.html \
		tdomcmd.html tnc.html

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
