PORTNAME=	makeindex
PORTVERSION=	3.0.8
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://ftp.linux.cz/pub/tex/local/indexing/makeindex3/ \
		http://ftp.cstug.cz/pub/tex/local/indexing/makeindex3/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose, formatter-independent index processor

CONFLICTS=	teTeX-base

WRKSRC=		${WRKDIR}/makeindex

post-patch:
	@(cd ${WRKSRC}/doc; \
	  ${SED} -e s:/usr/local/lib/tex/macros/:${PREFIX}/share/texmf/makeindx/: \
	      <makeindex.l >makeindex.1)
	@${REINPLACE_CMD} -E '/^CFLAGS/! s,(BIN|STY)DIR),DESTDIR)$$(&,' \
		${WRKSRC}/src-3.0/Makefile.gen

do-build:
	@(cd ${WRKSRC}/src-3.0/regexp; ${MAKE} OPT="${CFLAGS}")
	@(cd ${WRKSRC}/src-3.0; ${MAKE} OPT="${CFLAGS}")

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/texmf/makeindx
	@(cd ${WRKSRC}/src-3.0/regexp; ${MAKE})
	@(cd ${WRKSRC}/src-3.0; ${MAKE} install ${MAKE_ARGS})
	@(cd ${WRKSRC}/doc; \
	  ${INSTALL_DATA} makeindex.1 ${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>
