# New ports collection makefile for:	nicetext
# Date created:		20 February 1998
# Whom:			Mark Chapman <markc@ctgi.net>
#
# $FreeBSD$

PORTNAME=	nicetext
PORTVERSION=	0.9
CATEGORIES=	textproc
MASTER_SITES=	ftp://ctgi.net/pub/ctgi/nicetext/src/ \
		ftp://nicetext.com/pub/nicetext/src/

MAINTAINER=	markc@ctgi.net

USE_GMAKE=	YES
MAKE_FLAGS=	CXXFLAGS="${CXXFLAGS} -pedantic" CFLAGS="${CFLAGS} -pedantic"

MAN1=		bitcp.1 dct2mstr.1 expgram.1 genmodel.1 gramtest.1 impkimmo.1 \
		impmsc.1 impwbstr.1 listword.1 nicetext.1 nttpd.1 printint.1 \
		scramble.1 sortdct.1 txt2dct.1
PROGRAMS=	bitcp dct2mstr expgram genmodel gramtest impkimmo impmsc \
		impwbstr listword nicetext nttpd printint rinfo scramble \
		sortdct txt2dct

post-install:
	@${ECHO} "#!/bin/sh" > ${WRKSRC}/bin/qstart-nttpd
	@${ECHO} ${PREFIX}/bin/"nttpd -b " ${PREFIX}/share/examples/nicetext/database >> ${WRKSRC}/bin/qstart-nttpd
	${CHMOD} a+rx ${WRKSRC}/bin/qstart-nttpd
	${INSTALL_SCRIPT} ${WRKSRC}/bin/qstart-nttpd ${PREFIX}/bin/
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/man1/${f} ${PREFIX}/man/man1
.endfor
.for f in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${PREFIX}/bin/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/nicetext/
	${INSTALL_MAN} ${WRKSRC}/doc/* ${PREFIX}/share/doc/nicetext/
	${INSTALL_MAN} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/nicetext/
.endif
	${MKDIR} ${PREFIX}/share/examples/
	${MKDIR} ${PREFIX}/share/examples/nicetext/
	${INSTALL_DATA} ${WRKSRC}/examples/Makefile ${PREFIX}/share/examples/nicetext/
	${INSTALL_DATA} ${WRKSRC}/examples/README.TXT ${PREFIX}/share/examples/nicetext/
	${MKDIR} ${PREFIX}/share/examples/nicetext/database/
	${INSTALL_DATA} ${WRKSRC}/examples/database/* ${PREFIX}/share/examples/nicetext/database/
	${MKDIR} ${PREFIX}/share/examples/nicetext/texts/
	${INSTALL_DATA} ${WRKSRC}/examples/texts/Makefile ${PREFIX}/share/examples/nicetext/texts/
	${MKDIR} ${PREFIX}/share/examples/nicetext/texts/fabl/
	${INSTALL_DATA} ${WRKSRC}/examples/texts/fabl/* ${PREFIX}/share/examples/nicetext/texts/fabl/
	${MKDIR} ${PREFIX}/share/examples/nicetext/texts/jfk/
	${INSTALL_DATA} ${WRKSRC}/examples/texts/jfk/* ${PREFIX}/share/examples/nicetext/texts/jfk/
	${MKDIR} ${PREFIX}/share/examples/nicetext/texts/wizoz/
	${INSTALL_DATA} ${WRKSRC}/examples/texts/wizoz/* ${PREFIX}/share/examples/nicetext/texts/wizoz/
	${MKDIR} ${PREFIX}/share/examples/nicetext/texts/shak/
	${INSTALL_DATA} ${WRKSRC}/examples/texts/shak/* ${PREFIX}/share/examples/nicetext/texts/shak/
	${MKDIR} ${PREFIX}/share/examples/nicetext/tutorial/
	${INSTALL_DATA} ${WRKSRC}/examples/tutorial/Makefile ${PREFIX}/share/examples/nicetext/tutorial/
	${INSTALL_DATA} ${WRKSRC}/examples/tutorial/README.TXT ${PREFIX}/share/examples/nicetext/tutorial/
	${MKDIR} ${PREFIX}/share/examples/nicetext/tutorial/1/
	${INSTALL_DATA} ${WRKSRC}/examples/tutorial/1/* ${PREFIX}/share/examples/nicetext/tutorial/1/
	${MKDIR} ${PREFIX}/share/examples/nicetext/tutorial/2/
	${INSTALL_DATA} ${WRKSRC}/examples/tutorial/2/Makefile ${PREFIX}/share/examples/nicetext/tutorial/2/
	${INSTALL_DATA} ${WRKSRC}/examples/tutorial/2/README.TXT ${PREFIX}/share/examples/nicetext/tutorial/2/
	${INSTALL_DATA} ${WRKSRC}/examples/tutorial/2/sample.txt ${PREFIX}/share/examples/nicetext/tutorial/2/
	${INSTALL_DATA} ${WRKSRC}/examples/tutorial/2/secret.txt ${PREFIX}/share/examples/nicetext/tutorial/2/
	${MKDIR} ${PREFIX}/share/examples/nicetext/tutorial/2/words
	${INSTALL_DATA} ${WRKSRC}/examples/tutorial/2/words/* ${PREFIX}/share/examples/nicetext/tutorial/2/words/
	${MKDIR} ${PREFIX}/share/examples/nicetext/tutorial/3/
	${INSTALL_DATA} ${WRKSRC}/examples/tutorial/3/* ${PREFIX}/share/examples/nicetext/tutorial/3/
	${MKDIR} ${PREFIX}/share/examples/nicetext/words/wlist/
	${INSTALL_DATA} ${WRKSRC}/examples/words/wlist/Makefile ${PREFIX}/share/examples/nicetext/words/wlist/
	${MKDIR} ${PREFIX}/share/examples/nicetext/words/wlist/gutenberg/
	${INSTALL_DATA} ${WRKSRC}/examples/words/wlist/gutenberg/* ${PREFIX}/share/examples/nicetext/words/wlist/gutenberg/
	${MKDIR} ${PREFIX}/share/examples/nicetext/words/wlist/web2/
	${INSTALL_DATA} ${WRKSRC}/examples/words/wlist/web2/* ${PREFIX}/share/examples/nicetext/words/wlist/web2/
	${MKDIR} ${PREFIX}/share/examples/nicetext/words/twlist/
	${INSTALL_DATA} ${WRKSRC}/examples/words/twlist/Makefile ${PREFIX}/share/examples/nicetext/words/twlist/
	${MKDIR} ${PREFIX}/share/examples/nicetext/words/twlist/impkimmo/
	${INSTALL_DATA} ${WRKSRC}/examples/words/twlist/impkimmo/* ${PREFIX}/share/examples/nicetext/words/twlist/impkimmo/
	${MKDIR} ${PREFIX}/share/examples/nicetext/words/twlist/mitlist/
	${INSTALL_DATA} ${WRKSRC}/examples/words/twlist/mitlist/* ${PREFIX}/share/examples/nicetext/words/twlist/mitlist/
	${MKDIR} ${PREFIX}/share/examples/nicetext/words/twlist/numeric/
	${INSTALL_DATA} ${WRKSRC}/examples/words/twlist/numeric/* ${PREFIX}/share/examples/nicetext/words/twlist/numeric/
	${MKDIR} ${PREFIX}/share/examples/nicetext/words/twlist/rhyme/
	${INSTALL_DATA} ${WRKSRC}/examples/words/twlist/rhyme/* ${PREFIX}/share/examples/nicetext/words/twlist/rhyme/
.include <bsd.port.mk>
