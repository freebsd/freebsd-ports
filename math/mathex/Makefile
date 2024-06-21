PORTNAME=	mathex
DISTVERSION=	0.3-b
CATEGORIES=	math science devel
MASTER_SITES=	SF/sscilib/mathex

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	C++ library fo parse/evaluate mathematical expressions
WWW=		https://sscilib.sourceforge.net/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		dos2unix zip
DOS2UNIX_FILES=	makefile

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile
ALL_TARGET=	${PORTNAME}
USE_LDCONFIG=	yes

PLIST_FILES=	${PREFIX}/include/mathex.h	\
		${PREFIX}/lib/lib${PORTNAME}.so	\
		${PREFIX}/lib/lib${PORTNAME}.so.0
PLIST_FILES+=	${PROGS:C|^|${PREFIX}/bin/|}

PROGS=		curvetest inttest tabletest userfunctest

OPTIONS_DEFINE=	EXAMPLES

post-build:
	(cd ${WRKSRC} &&	\
	${CXX} ${LDFLAGS} -shared -o lib${PORTNAME}.so.0 -Wl,-soname,lib${PORTNAME}.so.0 ${PORTNAME}.o)

do-install:
	${INSTALL_DATA} ${WRKSRC}/mathex.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.so.0 ${STAGEDIR}${PREFIX}/lib/
	${LN} -s lib${PORTNAME}.so.0 ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so

do-install-EXAMPLES-on:
.for p in ${PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/${p} ${STAGEDIR}${PREFIX}/bin/
.endfor

.include <bsd.port.mk>
