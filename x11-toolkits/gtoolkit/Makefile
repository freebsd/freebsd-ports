# New ports collection makefile for:   gtoolkit
# Date created:        13 Jan 2002
# Whom:                Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	gtoolkit
PORTVERSION=	0.9.5
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.inf.uos.de/pub/elmar/gtk/objc-gtoolkit/

MAINTAINER=	dinoex@FreeBSD.org

BUILD_DEPENDS=  ${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/lang/gnustep-base
RUN_DEPENDS=    ${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/lang/gnustep-base

PREFIX=		${LOCALBASE}/GNUstep
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
NO_MTREE=	yes

MAKE_ARGS=	GNUSTEP_SYSTEM_ROOT=$(PREFIX)/System
CONFIGURE_ARGS+=	--with-gnustep
INSTALLS_SHLIB=	yes
WRKSRC= 	${WRKDIR}/${DISTNAME}/GToolKit
CONFIGURE_WRKSRC=	${WRKDIR}/${DISTNAME}

post-patch:
	@${MV} ${CONFIGURE_WRKSRC}/configure ${CONFIGURE_WRKSRC}/configure.sed
	${SED} -e 's#gtk-config#gtk12-config#g' \
		${CONFIGURE_WRKSRC}/configure.sed \
		> ${CONFIGURE_WRKSRC}/configure
	${CHMOD} +x ${CONFIGURE_WRKSRC}/configure

do-configure:
	@(cd ${CONFIGURE_WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
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

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif
PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} OPSYS=${OPSYS:L} VERSION=${PORTVERSION}

SYSTEMDIR=	${PREFIX}/System
SYSLIBDIR=	${SYSTEMDIR}/Libraries/${GNU_ARCH}/${OPSYS:L}
COMBOLIBDIR=	${SYSLIBDIR}/gnu-gnu-gnu

.include <bsd.port.post.mk>
