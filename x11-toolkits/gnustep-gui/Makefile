# New ports collection makefile for:    gnustep-gui
# Date created:         19 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-gui
.if defined(GNUSTEP_GUI_DEVEL)
PORTVERSION=	0.8.2
.else
PORTVERSION=	0.7.6
.endif
CATEGORIES=	x11-toolkits
.if defined(GNUSTEP_GUI_DEVEL)
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/core/
PKGNAMESUFFIX?=	-devel
.else
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
.endif

MAINTAINER=	dinoex@FreeBSD.org

BUILD_DEPENDS=	${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/lang/gnustep-base
RUN_DEPENDS=	${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/lang/gnustep-base
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
.if defined(GNUSTEP_GUI_DEVEL)
LIB_DEPENDS+=	audiofile.0:${PORTSDIR}/audio/libaudiofile
.endif

BREAKS_IF_PEDANTIC=	yes
.if defined(GNUSTEP_GUI_DEVEL)
PLIST_SUB+=	DEVEL=""
PLIST_SUB+=	NODEVEL="@comment "
.else
PLIST_SUB+=	DEVEL="@comment "
PLIST_SUB+=	NODEVEL=""
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
BROKEN=		"Sorry, this port does not work on FreeBSD-2.2.x"
.endif

PREFIX=		${LOCALBASE}/GNUstep
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
USE_GMAKE=	yes
MAKEFILE=
MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
NO_MTREE=	yes
CONFIGURE_ARGS+=	--with-tiff-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-tiff-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-jpeg-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-jpeg-include=${LOCALBASE}/include

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif
PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} OPSYS=${OPSYS:L} VERSION=${PORTVERSION} \
		MAJORVERSION=${PORTVERSION:C/([0-9]).*/\1/1}

COMBOLIBDIR=	${PREFIX}/System/Libraries/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu

post-extract:
.for file in config.guess config.sub install-sh
	@${CP} ${PREFIX}/System/Makefiles/${file} ${WRKSRC}
.endfor

do-configure:
	@(cd ${WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
	    if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
		INSTALL_DATA="${INSTALL} -c" \
		INSTALL_PROGRAM="${INSTALL} -c" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; then \
		    ${ECHO} "===>  Script \"${CONFIGURE_SCRIPT}\" failed: here are the contents of \"${CONFIGURE_LOG}\""; \
		    ${CAT} ${CONFIGURE_LOG}; \
		    ${ECHO} "(end of \"${CONFIGURE_LOG}\")"; \
		    ${FALSE}; \
	    fi)

do-build:
	@(cd ${WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})

do-install:
	@(cd ${WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
