# Created by: Heiner <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	dvdisaster
PORTVERSION=	0.72.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://dvdisaster.net/downloads/

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	CD/DVD error recovery tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

MAKEFILE=	GNUmakefile

USE_BZIP2=	yes
USES=		gettext
USE_GNOME=	gtk20
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--docsubdir="/" \
		--png-includes=${LOCALBASE}/include \
		--png-libraries=${LOCALBASE}/lib
USE_GMAKE=	yes
MAKE_JOBS_UNSAFE=yes

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--docdir=${WRKSRC}
.else
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
.endif

PORTDOCS=	*

PORTSCOUT=	limitw:1,even

MAN1=		dvdisaster.1
MANLANG=	"" cs de it

do-configure:
	@(cd ${CONFIGURE_WRKSRC} && \
		if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
	    CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	    INSTALL="${INSTALL} -c ${_BINOWNGRP}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} bash configure ${CONFIGURE_ARGS}; then \
			 ${ECHO_CMD} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
			 (${ECHO_CMD} ${CONFIGURE_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
			 ${FALSE}; \
		fi)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
