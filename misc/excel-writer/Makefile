# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	excel-writer
PORTVERSION=	07
CATEGORIES=	misc
MASTER_SITES=	http://sourceforge.net/projects/${SFPATH}/
DISTNAME=	excel_writer_${PORTVERSION}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Package for easily creating Excel files with basic formats

LICENSE=	MIT

USES=		ada zip dos2unix
SFPATH=		excel-writer/files/excel-writer/excel-writer-${PORTVERSION}
WRKSRC=		${WRKDIR}/Excel_Writer
PORTDOCS=	excel_writer.txt
PORTEXAMPLES=	example.gpr excel_out_test.adb runme.sh

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-extract:
	${CP} ${FILESDIR}/construct.gpr ${FILESDIR}/biff_dump.gpr ${WRKSRC}
	${MKDIR} ${WRKSRC}/src ${WRKDIR}/data
	${MV} ${WRKSRC}/Big.xls ${WRKDIR}/data
	(cd ${WRKSRC}; ${MV} excel_out.ad[bs] ieee* extras/csv.* src)
	${SED} -e "s,@PREFIX@,${LOCALBASE},g" ${FILESDIR}/runme.sh.in \
		> ${WRKSRC}/runme.sh

post-patch:
	@${REINPLACE_CMD} -e "s|Big.xls|${DATADIR}/Big.xls|" \
		-e 's|\$$Dump\$$|_dump_|g' ${WRKSRC}/extras/biff_dump.adb
	${REINPLACE_CMD} -e 's/"\(.*\.xls\)"/"\/tmp\/\1"/g' \
		${WRKSRC}/excel_out_test.adb

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -p -Pconstruct)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -p -Pbiff_dump)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/excel_writer \
		${STAGEDIR}${PREFIX}/include/excel_writer \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/excel_writer.gpr \
		${STAGEDIR}${PREFIX}/lib/gnat
	${INSTALL_DATA} ${WRKSRC}/src/* \
		${STAGEDIR}${PREFIX}/include/excel_writer
	${INSTALL_DATA} ${WRKSRC}/lib/*  \
		${STAGEDIR}${PREFIX}/lib/excel_writer
	${INSTALL_PROGRAM} ${WRKSRC}/bin/biff_dump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/data/Big.xls ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/excel_writer.txt ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/runme.sh ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/excel_out_test.adb \
		${FILESDIR}/example.gpr ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
