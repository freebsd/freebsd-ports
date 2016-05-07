# Created by: Aldert Nooitgedagt
# $FreeBSD$

PORTNAME=	tclwebtest
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	www tcl
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for issuing HTTP requests and dealing with the result

LICENSE=	GPLv2

RUN_DEPENDS=	tclsh:lang/tcl-wrapper

NO_BUILD=	YES

LIBDIR=		lib/tclwebtest${PORTVERSION}
PLIST_SUB+=	LIBDIR="${LIBDIR}"

OPTIONS_DEFINE=	DOCS

post-extract:
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -rf
	@${SED}	-i "" -e "s| tclsh | ${LOCALBASE}/bin/tclsh |g" ${WRKSRC}/tclwebtest

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${LIBDIR}
.for FILE in entities.tcl from_openacs.tcl pkgIndex.tcl tclwebtest.tcl
	${INSTALL_DATA} ${WRKSRC}/lib/${FILE} ${STAGEDIR}${PREFIX}/${LIBDIR}/${FILE}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/selftest ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/openacs4tests ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tclwebtest ${STAGEDIR}${PREFIX}/bin/tclwebtest

post-install:
	@${ECHO} "Installing docs"
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/doc
	${TAR} -C ${WRKSRC} -c -f - ChangeLog README TODO index.html generate_docs.test | ${TAR} -C ${STAGEDIR}${DOCSDIR} -x -f -
	${TAR} -C ${WRKSRC}/doc -c -f - . | ${TAR} -C ${STAGEDIR}${DOCSDIR}/doc -x -f -

.include <bsd.port.mk>
