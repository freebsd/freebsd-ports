# Created by: mich@freebsdcluster.org
# $FreeBSD$

PORTNAME=	gubby
PORTVERSION=	0.5.5
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Program showing where new mail has been placed

LDFLAGS+=	-lncurses
CFLAGS+=	-fno-exceptions -fno-rtti

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/curswin.o src/curswin.cpp && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/die.o src/die.cpp && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/exists.o src/exists.cpp && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/filechange.o src/filechange.cpp && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/folder.o src/folder.cpp && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/folders.o src/folders.cpp && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/getopts.o src/getopts.cpp && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/grep.o src/grep.cpp && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/gubby.o src/gubby.cpp && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/gubbycfg.o src/gubbycfg.cpp && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/gubbyopts.o src/gubbyopts.cpp && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/guess.o src/guess.cpp && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/initcurs.o src/initcurs.cpp && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/keys.o src/keys.cpp && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/runscreen.o src/runscreen.cpp && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/screens.o src/screens.cpp && \
	${CXX} -c ${CFLAGS} -Iinclude/ -o src/versioninfo.o src/versioninfo.cpp && \
	${CXX} -s ${CFLAGS} src/curswin.o src/die.o src/exists.o src/filechange.o src/folder.o \
	src/folders.o src/getopts.o src/grep.o src/gubby.o src/gubbycfg.o src/gubbyopts.o \
	src/guess.o src/initcurs.o src/keys.o src/runscreen.o src/screens.o src/versioninfo.o \
	${LDFLAGS} -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gubby ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/gubby.1 ${STAGEDIR}${PREFIX}/man/man1

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
