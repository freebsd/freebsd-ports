# New ports collection makefile for: tet
# Date created:		02 Oct 1998
# Whom:			jkoshy
#
# $FreeBSD$
#

PORTNAME=		tet
PORTVERSION=		3.3f
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.rdg.opengroup.org/pub/TET/TET3/ \
			${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkoshy
DISTFILES=		${PORTNAME}${PORTVERSION}-unsup.src.tar.gz

MAINTAINER=		jkoshy@freebsd.org

NO_WRKSUBDIR=		yes
NO_PACKAGE=		TET_ROOT needs to be set at compile time
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		-t ${TET_CONFIG_TARGET}

TET_CONFIG_TARGET?=	inet	# options are `lite', `xti' and `inet'

do-build:
	cd ${WRKDIR}/src && ${MAKE} ${ALL_TARGET}

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

# remove the TET_ROOT directory if it exists
pre-clean:
.if defined(TET_ROOT)
	${RM} -rf ${TET_ROOT}
.endif
	${RM} -rf ${WRKDIR}

# move the work directory to $TET_ROOT after extraction
post-extract:
	${CHMOD} +x ${WRKDIR}/configure
	${MKDIR} ${TET_ROOT}
	cd ${WRKDIR} && tar cf - . | (cd ${TET_ROOT} && tar xf -)
	${RM} -rf ${WRKDIR} && ${LN} -s ${TET_ROOT} ${WRKDIR}

do-install:
	cd ${WRKDIR}/src && ${MAKE} ${INSTALL_TARGET}

.include	<bsd.port.mk>
