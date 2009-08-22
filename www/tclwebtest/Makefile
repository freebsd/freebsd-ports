# New ports collection makefile for:	tclwebtest
# Date created:				July 2005
# Whom:					Aldert Nooitgedagt
#
# $FreeBSD$
#

PORTNAME=	tclwebtest
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	www tcl
MASTER_SITES=	SF

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Tool for issuing HTTP requests and dealing with the result

RUN_DEPENDS=	tclsh:${PORTSDIR}/lang/tcl-wrapper

NO_BUILD=	YES

LIBDIR=		lib/tclwebtest${PORTVERSION}
PLIST_SUB+=	LIBDIR="${LIBDIR}"

.include <bsd.port.pre.mk>

post-extract:
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -rf
	@${SED}	-i "" -e "s| tclsh | ${LOCALBASE}/bin/tclsh |g" ${WRKSRC}/tclwebtest

do-install:
	@${MKDIR} ${PREFIX}/${LIBDIR}
.for FILE in entities.tcl from_openacs.tcl pkgIndex.tcl tclwebtest.tcl
	${INSTALL_DATA} ${WRKSRC}/lib/${FILE} ${PREFIX}/${LIBDIR}/${FILE}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/selftest ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/openacs4tests ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tclwebtest ${PREFIX}/bin/tclwebtest

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO} "Installing docs"
	@${MKDIR} ${DOCSDIR}/doc
	@${TAR} -C ${WRKSRC} -c -f - ChangeLog README TODO index.html generate_docs.test | ${TAR} -C ${DOCSDIR} -x -f -
	@${TAR} -C ${WRKSRC}/doc -c -f - . | ${TAR} -C ${DOCSDIR}/doc -x -f -
.endif

.include <bsd.port.post.mk>
