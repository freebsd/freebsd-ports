# New ports collection makefile for: tet
# Version required: 	3.2b
# Date created:		02 Oct 1998
# Whom:			jkoshy
#
# $Id: Makefile,v 1.1.1.1 1998/10/21 08:31:08 jkoshy Exp $
#

DISTNAME=		tet3.2c-unsup
PKGNAME=		tet-3.2c
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.rdg.opengroup.org/pub/TET/TET3
EXTRACT_SUFX=		.src.tgz

MAINTAINER=		jkoshy@freebsd.org

NO_WRKSUBDIR=		yes
NO_PACKAGE=		TET_ROOT needs to be set at compile time
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		-t ${TET_CONFIG_TARGET}

TET_CONFIG_TARGET?=	inet	# options are `lite', `xti' and `inet'

do-build:
	cd ${WRKDIR}/src && ${MAKE} ${ALL_TARGET}

pre-extract pre-clean:
.if !defined(TET_ROOT)
	@echo
	@echo "The environment variable \"TET_ROOT\" is not set."
	@echo "You must set it to the directory where you would like "
	@echo "this port to reside before attempting extraction or cleaning."
	@echo
	@false
.else
	@true
.endif

# move the work directory to $TET_ROOT after extraction
post-extract:
	chmod +x ${WRKDIR}/configure
	${MKDIR} ${TET_ROOT}
	cd ${WRKDIR} && tar cf - . | (cd ${TET_ROOT} && tar xf -)
	${RM} -rf ${WRKDIR} && ${LN} -s ${TET_ROOT} ${WRKDIR}

do-install:
	cd ${WRKDIR}/src && ${MAKE} ${INSTALL_TARGET}

post-clean:
	${RM} -rf ${TET_ROOT}

.include	<bsd.port.mk>
