# $FreeBSD$

PORTNAME=		voc
PORTVERSION=	g20191119
CATEGORIES=		lang

MAINTAINER=		antranigv@freebsd.am
COMMENT=		Vishap Oberon Compiler for Oberon-2

LICENSE=		GPLv3

USE_GITHUB=		yes
GH_ACCOUNT=		vishaps
GH_PROJECT=		voc
GH_TAGNAME=		63008f6

MAKE_JOBS_UNSAFE=	yes

MAKEFILE=		makefile
ALL_TARGET=		full

USE_LDCONFIG=		${PREFIX}/share/voc/lib

post-patch:
	# we cannot run ldconfig (which is what addlibrary does) on the destination
	# so we set USE_LDCONFIG instead, and disable addlibrary.sh
	${PRINTF} '#!/bin/sh\ntrue\n' >${WRKSRC}/src/tools/make/addlibrary.sh

do-install:
	(cd ${WRKSRC} && INSTALLDIR=${STAGEDIR}${PREFIX}/share/voc ${MAKE_CMD} install)
.for i in bin/voc bin/showdef lib/libvoc-OC.so lib/libvoc-O2.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/voc/${i}
.endfor
.for i in bin/voc bin/showdef
	${LN} -s ../share/voc/${i} ${STAGEDIR}${PREFIX}/bin/
.endfor

.include <bsd.port.mk>
