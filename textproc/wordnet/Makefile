# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	WordNet
PORTVERSION=	3.0
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://wordnetcode.princeton.edu/${PORTVERSION}/:code \
		http://wordnetcode.princeton.edu/:dict
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:code wn3.1.dict.tar.gz:dict

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Dictionaries and thesauri with devel. libraries (C, TCL) and browsers

EXTRACT_ONLY=	${DISTFILES:M*code:S/:code//}
EXTRACT_AFTER_ARGS=--exclude dict
USES=		tcl uidfix tar:bzip2
SCRIPTS_ENV+=	TCL_DVER=${TCL_VER} VER=${PORTVERSION}
MAKE_ENV+=	TCL_DVER=${TCL_VER} VER=${PORTVERSION} STAGEDIR="${STAGEDIR}"
PLIST_SUB+=	TCL_DVER=${TCL_VER} VER=${PORTVERSION}
REINPLACE_ARGS=	-i ""
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message
SUB_LIST+=	TCL_VER=${TCL_VER}

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' \
	    ${WRKSRC}/src/wnb ${WRKSRC}/doc/man/*.?
	${REINPLACE_CMD} -e 's,  *\\n,\\n,' ${WRKSRC}/include/wn.h

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${TAR} -C ${STAGEDIR}${DATADIR} -x --no-same-owner	\
	    --strip-components 1	\
	    -f ${_DISTDIR}${DISTFILES:M*dict:S/:dict//}	\
	    `${SED} -n -e '/\.xbm/d' -e 's,^%%DATADIR%%/,dict/,p' ${PLIST}`

.include <bsd.port.mk>
