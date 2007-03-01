# New ports collection makefile for:	tclwebtest
# Date created:				July 2005
# Whom:					Aldert Nooitgedagt
#
# $FreeBSD$
#

PORTNAME=	tclwebtest
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	www tcl84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	martin@matuska.org
COMMENT=	Tool for issuing HTTP requests and dealing with the result

USE_TCL_VER?=	84

.if ${USE_TCL_VER} != 84 && ${USE_TCL_VER} != 85
IGNORE=		supported values for USE_TCL_VER are only 84 and 85
.endif

# by default we want tcl with threads as dependency (www/openacs)
USE_TCL=	${USE_TCL_VER}-thread

NO_BUILD=	YES

TWTBASE=	${PREFIX}/tclwebtest-${PORTVERSION}
TWTBASEL=	${PREFIX}/tclwebtest

.include <bsd.port.pre.mk>

.if exists(${TCLSH})
_TCL_IS_THREADED!=	${ECHO_CMD} 'puts [array names tcl_platform -exact threaded]' | ${TCLSH} || return 0
. if empty(_TCL_IS_THREADED)
# Check if a threaded build is forced
.  if defined(TCL_WITH_THREADS) || defined(WITH_THREADS)
IGNORE=	tcl with threads is required. Please install tcl with WITH_THREADS defined or from lang/tcl${USE_TCL} port and try again
.  else
# Installed tcl is not threaded, so set correct dependencies
USE_TCL=${USE_TCL_VER}
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
.  endif
. endif
.endif

PLIST_SUB+=	TWTDIR=tclwebtest-${PORTVERSION} TCLLIB=${TCL_LIBDIR:S/${LOCALBASE}\///g}

post-extract:
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -rf
	@${SED}	-i "" -e "s| tclsh | ${TCLSH} |g" ${WRKSRC}/tclwebtest

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
	@${TEST} -L ${TCL_LIBDIR}/tclwebtest || ${LN} -s ${TWTBASEL}/lib ${TCL_LIBDIR}/tclwebtest
	@${TEST} -L ${PREFIX}/bin/tclwebtest || ${LN} -s ${TWTBASEL}/tclwebtest ${PREFIX}/bin

	@${ECHO_CMD} "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@${ECHO_CMD} " You may need to set TCLLIBPATH in your environment. "
	@${ECHO_CMD} " Set it to ${TWTBASEL} if tclwebtest barks at you. "
	@${ECHO_CMD} "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"

.include <bsd.port.post.mk>
