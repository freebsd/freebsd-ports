# New ports collection makefile for: tet
# Version required: 	3.2b
# Date created:		02 Oct 1998
# Whom:			jkoshy
#
# $Id: Makefile,v 1.5 1998/11/28 09:33:21 asami Exp $
#

DISTNAME=		tet3.2e-unsup
PKGNAME=		tet-3.2e
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.rdg.opengroup.org/pub/TET/TET3/ \
			http://freefall.freebsd.org/~jkoshy/PORTS/
EXTRACT_SUFX=		.src.tgz

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
	@echo
	@echo "The environment variable \"TET_ROOT\" is not set."
	@echo "You must set it to the directory where you would like "
	@echo "this port to reside before attempting extraction."
	@echo
	@false
.else
	@true
.endif

# remove the TET_ROOT directory if it exists
pre-clean:
.if defined(TET_ROOT)
	${RM} -rf ${TET_ROOT}
.endif
	${RM} -rf ${WRKDIR}

# move the work directory to $TET_ROOT after extraction
post-extract:
	chmod +x ${WRKDIR}/configure
	${MKDIR} ${TET_ROOT}
	cd ${WRKDIR} && tar cf - . | (cd ${TET_ROOT} && tar xf -)
	${RM} -rf ${WRKDIR} && ${LN} -s ${TET_ROOT} ${WRKDIR}

do-install:
	cd ${WRKDIR}/src && ${MAKE} ${INSTALL_TARGET}

.include	<bsd.port.mk>
