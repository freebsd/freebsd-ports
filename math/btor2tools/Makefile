# $FreeBSD$

PORTNAME=	btor2tools
DISTVERSION=	g20190418
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic parser and tool package for the BTOR2 format

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	Boolector
GH_TAGNAME=	1df768d
USE_LDCONFIG=	yes

MAKEFILE=	makefile

PLIST_FILES=	bin/btorsim \
		bin/catbtor \
		include/btor2parser/btor2parser.h \
		lib/libbtor2parser.so

do-configure:
	@cd ${WRKSRC} && CFLAGS="" CC=${CC} ./configure.sh -shared -fPIC

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/btor2parser
	${INSTALL_DATA} ${WRKSRC}/src/btor2parser/btor2parser.h ${STAGEDIR}${PREFIX}/include/btor2parser
	${INSTALL_LIB} ${WRKSRC}/build/libbtor2parser.so ${STAGEDIR}${PREFIX}/lib
.for exe in btorsim catbtor
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${exe} ${STAGEDIR}${PREFIX}/bin
.endfor

do-test:
	@cd ${WRKSRC} && LD_PRELOAD=${WRKSRC}/build/libbtor2parser.so test/runtests.sh

.include <bsd.port.mk>
