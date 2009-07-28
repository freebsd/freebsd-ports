# New ports collection makefile for:    dvdisaster
# Date created:                         2006/08/13
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	dvdisaster
PORTVERSION=	0.72
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	A CD/DVD error recovery tool

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	GNUmakefile

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--png-includes=${LOCALBASE}/include \
		--png-libraries=${LOCALBASE}/lib
USE_GMAKE=	yes

PORTSCOUT=	limitw:1,even

MAN1=		dvdisaster.1
MANLANG=	"" cs de it

PLIST_SUB=	PORTVERSION=${PORTVERSION}

do-configure:
	@(cd ${CONFIGURE_WRKSRC} && \
		if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
	    CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	    INSTALL="/usr/bin/install -c ${_BINOWNGRP}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} bash configure ${CONFIGURE_ARGS}; then \
			 ${ECHO_CMD} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
			 (${ECHO_CMD} ${CONFIGURE_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
			 ${FALSE}; \
		fi)

.include <bsd.port.mk>
