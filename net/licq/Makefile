# New ports collection makefile for:    licq
# Date created:                         2 July 1998
# Whom:                                 Brian Feldman & Matt Heckaman
#
# $FreeBSD$
#

PORTNAME=	licq
PORTVERSION=	1.0.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.wibble.net/pub/licq/srcs/ \
		ftp://licq.darkorb.net/srcs/ \
		ftp://ftp.fanfic.org/pub/licq/srcs/ \
		ftp://ftp.inter-i.uni-mainz.de/pub/licq/srcs/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	green@FreeBSD.org

BUILD_DEPENDS=	aclocal:${PORTSDIR}/devel/automake

USE_QT_VER=	2
USE_GMAKE=	yes
USE_AUTOCONF=	yes
USE_OPENSSL=	yes
USE_PERL5=	yes

CONFIGURE_TARGET=	$(ARCH)-unknown-freebsdelf$(OSREL)

post-patch:
	@${PERL} -pi.orig -e 's:<wait\.h>:<sys/wait.h>:g' \
	    ${WRKSRC}/src/sighandler.c

post-configure:
	@(cd ${WRKSRC}/plugins/qt-gui-${PORTVERSION} && ${AUTOCONF})
	@(cd ${WRKSRC}/plugins/qt-gui-${PORTVERSION} && \
		if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
	    CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	    INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    QTBASE="${X11BASE}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} \
		--enable-spoofing; then \
			${ECHO} "===>  Script \"${CONFIGURE_SCRIPT}\" failed: here are the contents of \"${CONFIGURE_LOG}\""; \
			${CAT} ${CONFIGURE_LOG}; \
			${ECHO} "(end of \"${CONFIGURE_LOG}\")"; \
			${FALSE}; \
		fi)

post-build:
	@(cd ${WRKSRC}/plugins/qt-gui-${PORTVERSION}; \
	   ${SETENV} ${MAKE_ENV} \
	   ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

pre-install:
	${RM} -rf ${PREFIX}/share/licq
	${MKDIR} -m 700 ${PREFIX}/share/licq

post-install:
	cd ${WRKSRC}/plugins/qt-gui-${PORTVERSION}; \
	   ${SETENV} ${MAKE_ENV} \
	   ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
	${CHMOD} -R a-w ${PREFIX}/share/licq
	${CHMOD} 755 ${PREFIX}/share/licq

.include <bsd.port.mk>
