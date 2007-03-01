# New ports collection makefile for:	tDOM
# Date created:				July 2005
# Whom:					Aldert Nooitgedagt
#
# $FreeBSD$
#

PORTNAME=	tDOM
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.tdom.org/files/
PKGNAMESUFFIX?=	-threads

MAINTAINER=	aldert@nooitgedagt.net
COMMENT=	High performance XML data processing with Tcl (ARGS for OpenACS)

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/unix
TDOMBASE=	${PREFIX}/lib/tdom${PORTVERSION}

USE_TCL_VER?=	84

.if ${USE_TCL_VER} != 84 && ${USE_TCL_VER} != 85
IGNORE=		supported values for USE_TCL_VER are only 84 and 85
.endif

# by default we want a threaded build
USE_TCL=	${USE_TCL_VER}-thread
USE_TCL_BUILD=	${USE_TCL_VER}-thread

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

.if exists(${TCLSH})
_TCL_IS_THREADED!=	${ECHO_CMD} 'puts [array names tcl_platform -exact threaded]' | ${TCLSH} || return 0
. if empty(_TCL_IS_THREADED)
# Check if a threaded build is forced
.  if defined(TCL_WITH_THREADS) || defined(WITH_THREADS)
IGNORE=	tcl with threads is required. Please install tcl with WITH_THREADS defined or from lang/tcl${USE_TCL} port and try again
.  else
# Installed tcl is not threaded, so set correct dependencies
CONFIGURE_ARGS+=	--disable-threads
PKGNAMESUFFIX=
USE_TCL=${USE_TCL_VER}
USE_TCL_BUILD=${USE_TCL_VER}
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
.  endif
. else
CONFIGURE_ARGS+=	--enable-threads
. endif
.else
CONFIGURE_ARGS+=	--enable-threads
.endif

CONFIGURE_ARGS+=	-disable-tdomalloc --with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR}  --prefix=${PREFIX}

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
