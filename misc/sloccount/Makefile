PORTNAME=	sloccount
PORTVERSION=	2.26
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.dwheeler.com/sloccount/

MAINTAINER=	freaky@aagh.net
COMMENT=	Counts physical Source Lines of Code (SLOC)

USES=		perl5 shebangfix
SHEBANG_FILES=	asm_count break_filelist cobol_count count_extensions \
		f90_count fortran_count generic_count get_sloc \
		get_sloc_details haskell_count lex_count modula3_count \
		objc_count perl_count print_sum python_count sql_count

MAKEFILE=	makefile
INSTALL_TARGET=	install_programs install_man

PORTDOCS=	ChangeLog README TODO sloccount.html

OPTIONS_DEFINE=	DOCS

post-install:
.for file in lexcount1 c_count java_count php_count
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
