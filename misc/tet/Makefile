# New ports collection makefile for: tet
# Date created:		02 Oct 1998
# Whom:			jkoshy
#
# $FreeBSD$
#

PORTNAME=		tet
PORTVERSION=		3.3h
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.rdg.opengroup.org/pub/TET/TET3/ \
			${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkoshy
DISTNAME=		${PORTNAME}${PORTVERSION}-unsup.src
EXTRACT_SUFX=		.tgz

MAINTAINER=		jkoshy@freebsd.org
COMMENT=		An test execution framework from the Open Group

NO_WRKSUBDIR=		yes
NO_PACKAGE=		TET_ROOT needs to be set at compile time
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		-t ${TET_CONFIG_TARGET}
NO_BUILD=		yes
PLIST=			${WRKDIR}/PLIST

TET_CONFIG_TARGET?=	inet	# options are `lite', `xti' and `inet'

pre-extract:
.if !defined(TET_ROOT)
	@${ECHO_MSG}
	@${ECHO_MSG} "The environment variable \"TET_ROOT\" is not set."
	@${ECHO_MSG} "You must set it to the directory where you would like "
	@${ECHO_MSG} "this port to reside before attempting extraction."
	@${ECHO_MSG}
	@${FALSE}
.else
	@${TRUE}
.endif

# fix permissions
pre-configure:
	${CHMOD} +x ${WRKDIR}/configure

# move the work directory to $TET_ROOT after extraction, and build
# TET inside of $TET_ROOT
pre-install:
	${MKDIR} ${TET_ROOT}
	cd ${WRKDIR} && ${TAR} -cf - * | \
		(cd ${TET_ROOT} && ${TAR} xf -)
	cd ${TET_ROOT}/src && ${MAKE} ${ALL_TARGET}
	cd ${TET_ROOT}/src && ${MAKE} ${INSTALL_TARGET}
	${ECHO} "@cwd ${TET_ROOT}" > ${PLIST}
	cd ${TET_ROOT} && ${FIND} . ! -type d | \
		${SED} -e 's,^\./,,' >> ${PLIST}
	cd ${TET_ROOT} && ${FIND} -d . -type d -print | ${SORT} -ru | \
		${SED} -e 's,^\./,,' -e '/^\.$$/d' -e 's/^/@dirrm /' \
		>> ${PLIST}
	${ECHO} "@unexec ${RMDIR} ${TET_ROOT}" >> ${PLIST}

do-install:
	@${TRUE}

.include	<bsd.port.mk>
