# New ports collection makefile for:	wordnet
# Date created:		26 Feb 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	WordNet
PORTVERSION=	2.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cogsci.princeton.edu/pub/wordnet/${PORTVERSION}/ \
		http://wordnet.princeton.edu/${PORTVERSION}/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Dictionaries and thesauri with devel. libraries (C, TCL) and browsers

LIB_DEPENDS=	tk${TCL_VER}:${PORTSDIR}/x11-toolkits/tk${TCL_VER}

TCL_DVER?=	8.4
TCL_VER=	${TCL_DVER:C/\.//}
SCRIPTS_ENV+=	TCL_DVER=${TCL_DVER} VER=${PORTVERSION}
MAKE_ENV+=	TCL_DVER=${TCL_DVER} VER=${PORTVERSION}
PLIST_SUB+=	TCL_DVER=${TCL_DVER} VER=${PORTVERSION}
USE_BZIP2=	yes
REINPLACE_ARGS=	-i ""
INSTALLS_SHLIB=	yes

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local/WordNet-2.1,${DATADIR},g' \
	    ${WRKSRC}/src/wnb ${WRKSRC}/doc/man/*.?
	${REINPLACE_CMD} -e 's,  *\\n,\\n,' ${WRKSRC}/include/wn.h

.include <bsd.port.pre.mk>

.for s in 1 3 5 7
MAN$s	!=	${MAKE} -f ${FILESDIR}/man.Makefile -V MAN$s
.endfor

.include <bsd.port.post.mk>
