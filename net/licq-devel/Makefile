# New ports collection makefile for:    licq
# Date created:                         2 July 1998
# Whom:                                 Brian Feldman & Matt Heckaman
#
# $FreeBSD$
#

PORTNAME=	licq
PORTVERSION=	0.81
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.wibble.net/pub/licq/srcs/ \
		ftp://licq.darkorb.net/srcs/ \
		ftp://ftp.fanfic.org/pub/licq/srcs/ \
		ftp://ftp.inter-i.uni-mainz.de/pub/licq/srcs/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATAFILES}

MAINTAINER=	green@FreeBSD.org

LIB_DEPENDS=	qt2.3:${PORTSDIR}/x11-toolkits/qt21
BUILD_DEPENDS=	aclocal:${PORTSDIR}/devel/automake

USE_GMAKE=	yes
USE_AUTOCONF=	yes
USE_NEWGCC=     yes
USE_PERL5=      yes

DATANAME=       licq-data-1.6
DATAFILES=	${DATANAME}${EXTRACT_SUFX}
DATADIR=	${WRKDIR}/${DATANAME}

post-configure:
	@(cd ${WRKSRC}/plugins/qt-gui && \
		if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
	    CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	    INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} \
		--enable-spoofing; then \
			${ECHO} "===>  Script \"${CONFIGURE_SCRIPT}\" failed: here are the contents of \"${CONFIGURE_LOG}\""; \
			${CAT} ${CONFIGURE_LOG}; \
			${ECHO} "(end of \"${CONFIGURE_LOG}\")"; \
			${FALSE}; \
		fi)

post-build:
	@(cd ${WRKSRC}/plugins/qt-gui;\
	   ${SETENV} ${MAKE_ENV} \
	   ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

post-install:
	strip ${PREFIX}/bin/licq
	cd ${WRKSRC}/plugins/qt-gui;\
	   ${SETENV} ${MAKE_ENV} \
	   ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
	strip ${PREFIX}/lib/licq/licq_qt-gui.so
	${MKDIR} ${PREFIX}/share/licq/contrib
	${INSTALL_SCRIPT} ${DATADIR}/contrib/licq.* ${PREFIX}/share/licq/contrib
	${INSTALL_SCRIPT} ${DATADIR}/contrib/*.sh ${PREFIX}/share/licq/contrib
	${MKDIR} ${PREFIX}/share/licq/sounds/icq
	${INSTALL_DATA} ${DATADIR}/sounds/*.wav ${PREFIX}/share/licq/sounds
	${INSTALL_DATA} ${DATADIR}/sounds/icq/*.wav ${PREFIX}/share/licq/sounds/icq
	${MKDIR} ${PREFIX}/share/licq/translations
	${INSTALL_DATA} ${DATADIR}/translations/* ${PREFIX}/share/licq/translations
	${MKDIR} ${PREFIX}/share/licq/qt-gui
	cd ${DATADIR}/qt-gui && ${TAR} -chf - * | \
		${TAR} -xf - -C ${PREFIX}/share/licq/qt-gui

.include <bsd.port.mk>
