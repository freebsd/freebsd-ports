# ex:ts=8
# New ports collection makefile for:	gubby
# Date created:			Feb 4, 2003
# Whom:				mich@freebsdcluster.org
#
# $FreeBSD$
#

PORTNAME=	gubby
PORTVERSION=	0.5.5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A program showing where new mail has been placed

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

LDFLAGS+=	-lncurses
CFLAGS+=	-fno-exceptions -fno-rtti

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
	${INSTALL_PROGRAM} ${WRKSRC}/gubby ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${PREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${DOCSDIR}/README
.endif

MAN1=		gubby.1
.include <bsd.port.mk>
