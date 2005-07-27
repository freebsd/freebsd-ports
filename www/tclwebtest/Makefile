# New ports collection makefile for:	tclwebtest
# Date created:				July 2005
# Whom:					Aldert Nooitgedagt
#
# $FreeBSD$
#

PORTNAME=	tclwebtest
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	aldert@nooitgedagt.net
COMMENT=	Tool for issuing HTTP requests and dealing with the result

LIB_DEPENDS+=	tcl84.1:${PORTSDIR}/lang/tcl84-thread

NO_BUILD=	YES

TCLVERSION=	8.4
TWTBASE=	${PREFIX}/tclwebtest-${PORTVERSION}
TWTBASEL=	${PREFIX}/tclwebtest

PLIST_SUB+=	TWTDIR=tclwebtest-${PORTVERSION} TCLLIB=lib/tcl${TCLVERSION}

post-extract:
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -rf
	@${SED}	-i "" -e "s| tclsh | tclsh${TCLVERSION} |g" ${WRKSRC}/tclwebtest

do-install:
	@${TEST} -d ${TWTBASE} || ( ${MKDIR} ${TWTBASE} && \
		 ${CP} -R ${WRKSRC}/lib  ${TWTBASE} && \
		 ${CP} -R ${WRKSRC}/selftest  ${TWTBASE} && \
		 ${CP} ${WRKSRC}/tclwebtest  ${TWTBASE} )
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/openacs4tests ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	@${ECHO} "Installing docs"
	@${MKDIR} ${DOCSDIR}/doc
	@${TAR} -C ${WRKSRC} -c -f - ChangeLog README TODO index.html generate_docs.test | ${TAR} -C ${DOCSDIR} -x -f -
	@${TAR} -C ${WRKSRC}/doc -c -f - . | ${TAR} -C ${DOCSDIR}/doc -x -f -
.endif

post-install:
	@${TEST} -L ${TWTBASEL} || ${LN} -s ${TWTBASE} ${TWTBASEL}
	@${TEST} -L ${LOCALBASE}/lib/tcl${TCLVERSION}/tclwebtest || ${LN} -s ${TWTBASEL}/lib ${LOCALBASE}/lib/tcl${TCLVERSION}/tclwebtest
	@${TEST} -L ${PREFIX}/bin/tclwebtest || ${LN} -s ${TWTBASEL}/tclwebtest ${PREFIX}/bin

	@${ECHO_CMD} "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@${ECHO_CMD} " You may need to set TCLLIBPATH in your environment. "
	@${ECHO_CMD} " Set it to ${TWTBASEL} if tclwebtest barks at you. "
	@${ECHO_CMD} "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"

.include <bsd.port.mk>
