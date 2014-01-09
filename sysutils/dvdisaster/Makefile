# Created by: Heiner <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	dvdisaster
PORTVERSION=	0.72.5
CATEGORIES=	sysutils
MASTER_SITES=	http://dvdisaster.net/downloads/

MAINTAINER=	horia@racoviceanu.com
COMMENT=	CD/DVD error recovery tool

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

MAKEFILE=	GNUmakefile

USES=		gmake pkgconfig
USE_BZIP2=	yes
USE_GNOME=	gtk20
CONFIGURE_LOG=	configure.log
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--docsubdir="/" \
		--png-includes=${LOCALBASE}/include \
		--png-libraries=${LOCALBASE}/lib \
		--phpmountdir=${LOCALBASE}/www/${PORTNAME} \
		--mandir=${PREFIX}/man \
		--localedir=${PREFIX}/share/locale \
		--buildroot=${STAGEDIR}
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

DOCS_CONFIGURE_ON=	--docdir=${DOCSDIR}
DOCS_CONFIGURE_OFF=	--docdir=${WRKSRC}

NLS_USES=	gettext

post-patch:
	${REINPLACE_CMD} -e '/REQUIRE_GCC/d' \
		${WRKSRC}/configure ${WRKSRC}/tools/configure
	${REINPLACE_CMD} -e 's|$$(CFG_GTK2_CFLAGS)|$$(CFG_GTK2_CFLAGS) -w|' \
		${WRKSRC}/GNUmakefile.template
	${REINPLACE_CMD} -e 's|(ctx)|(*ctx)|' \
		${WRKSRC}/md5.c

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

.include <bsd.port.mk>
