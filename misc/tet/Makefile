# New ports collection makefile for: tet
# Date created:		02 Oct 1998
# Whom:			jkoshy
#
# $FreeBSD$
#

PORTNAME=		tet
PORTVERSION=		3.7
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.rdg.opengroup.org/pub/TET/TET3/ \
			http://tetworks.opengroup.org/tet/ \
			http://tetworks.opengroup.org/documents/3.7/:docs \
			${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkoshy
DISTFILES=		${PORTNAME}${PORTVERSION}-unsup.src.tgz
DIST_SUBDIR=		tet/${PORTVERSION}
EXTRACT_ONLY=		${PORTNAME}${PORTVERSION}-unsup.src.tgz

MAINTAINER=		jkoshy@freebsd.org
COMMENT=		An test execution framework from the Open Group

NO_PACKAGE=		$${TET_ROOT} needs to be set at compile time.
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		-t ${TET_CONFIG_TARGET}
PLIST=			${WRKDIR}/PLIST

TET_CONFIG_TARGET?=	inet	# options are `lite', `xti' and `inet'

.if !defined(NOPORTDOCS)
TET_DOCS=		37_all_pdf.zip
DISTFILES+=		${TET_DOCS}:docs
BUILD_DEPENDS+=		unzip:${PORTSDIR}/archivers/unzip
.endif

# Set @cwd in the package list to ${TET_ROOT}
PKG_ARGS=		-v -c -${COMMENT:Q} -d ${DESCR} -f ${TMPPLIST} \
			-p ${TET_ROOT} -o ${CATEGORIES}/${PORTNAME}

do-extract:
.if !defined(TET_ROOT)
	@${ECHO_MSG}
	@${ECHO_MSG} "ERROR: The environment variable \"TET_ROOT\" is not set."
	@${ECHO_MSG} "You must set it to the directory where you would like "
	@${ECHO_MSG} "this port to reside before attempting extraction."
	@${ECHO_MSG}
	@${FALSE}
.endif
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	${MKDIR} ${TET_ROOT}
	${LN} -s ${TET_ROOT} ${WRKDIR}/${PORTNAME}-${PORTVERSION}
	cd ${TET_ROOT} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/${EXTRACT_ONLY} ${EXTRACT_AFTER_ARGS}

# fix permissions
pre-configure:
	${CHMOD} +x ${TET_ROOT}/configure

# build TET inside ${TET_ROOT}, and create a default packing list so that
# pkg_delete tet-${PORTVERSION} will work.
do-build:
.if !defined(TET_ROOT)
	@${ECHO_MSG} ERROR: Environment variable \"TET_ROOT\" must be set.
	@${FALSE}
.endif
	cd ${TET_ROOT}/src && ${MAKE} ${ALL_TARGET}
	cd ${TET_ROOT}/src && ${MAKE} ${INSTALL_TARGET}
.if !defined(NOPORTDOCS)
	${MKDIR} ${TET_ROOT}/doc
	${UNZIP_CMD} -d ${TET_ROOT}/doc ${DISTDIR}/${DIST_SUBDIR}/${TET_DOCS}
.endif
	cd ${TET_ROOT} && ${FIND} . ! -type d | \
		${SED} -e 's,^\./,,' >> ${PLIST}
	cd ${TET_ROOT} && ${FIND} -d . -type d -print | ${SORT} -ru | \
		${SED} -e 's,^\./,,' -e '/^\.$$/d' -e 's/^/@dirrm /' \
		>> ${PLIST}
	${ECHO} "@unexec ${RMDIR} ${TET_ROOT}" >> ${PLIST}

do-install:
	@${TRUE}

.include	<bsd.port.mk>
