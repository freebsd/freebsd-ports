# New ports collection makefile for:		xdelta
# Date created:    01 April 2007
# Whom:            Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	xdelta
DISTVERSION=	3.0y
PORTREVISION?=	0
PORTEPOCH?=	1
CATEGORIES?=	misc devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Open-source binary diff, VCDIFF/RFC 3284 delta compression

USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${SLAVE_PORT:Mno}
PLIST_FILES=	bin/xdelta3
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/^CFLAGS/s/=/+&/' \
		-e 's/-O3//; s/-g//' \
		-e '/^all:/,/^$$/ { s/:.*/: xdelta3/; /testing/d; }' \
		${WRKSRC}/Makefile
.if ${SLAVE_PORT:Myes}
	${REINPLACE_CMD} -i.slave.bak -e '/^SWIG_FLAGS/s/=/& `python$$(PYVER)-config --cflags` -fpic/' \
		-e '/^xdelta3module\.so:/,/^$$/ { s/ld/$$(CC)/; \
			s/.*libpython.*\.so.*/`python$$(PYVER)-config --ldflags`/; \
			/-lc/d; }' \
		-e 's|/usr/include/python$$(PYVER)|${PYTHON_INCLUDEDIR}|' \
		-e 's|/usr/lib/python$$(PYVER)|${PYTHON_LIBDIR}|' \
		-e 's|/usr/lib/libpython|${LOCALBASE}/lib/libpython|' \
		-e '/^all:/s/:.*/: swigtgt/' \
		-e '/^PYVER/s/=.*/= ${PYTHON_VER}/' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "/^REL/s/=.*/='${PORTVERSION}'/" \
		-e "/extra_compile_args.*\[/,/]/ { s/'-O3',//; s/'-g',//; }" \
		${WRKSRC}/${PYSETUP}
.else
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdelta3 ${PREFIX}/bin/
.endif

.include <bsd.port.post.mk>
