# New ports collection makefile for:    libsphinxclient
# Date created:         2011-06-6
# Whom:                 Max Baryshnikov <mephius@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libsphinxclient
DISTVERSION=	1.10b
CATEGORIES=	textproc databases
MASTER_SITES=	http://sphinxsearch.com/files/
DISTNAME=	sphinx-1.10-beta

MAINTAINER=	mephius@gmail.com
COMMENT=	Sphinx Full-Text Search Engine C++ client library

WRKSRC=		${WRKDIR}/${DISTNAME}/api/libsphinxclient

USE_LDCONFIG=	yes

LICENSE=	GPLv2

USE_AUTOTOOLS=	libtool

.include <bsd.port.options.mk>

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CC=${CC}
SUB_LIST+=	PORTNAME=${PORTNAME}

do-install:
	${INSTALL_LIB} ${WRKSRC}/.libs/libsphinxclient-0.0.1.so ${PREFIX}/lib/libsphinxclient-0.0.1.so
	${INSTALL_DATA} ${WRKSRC}/libsphinxclient.la ${PREFIX}/lib/libsphinxclient.la
	${INSTALL_DATA} ${WRKSRC}/.libs/libsphinxclient.a ${PREFIX}/lib/libsphinxclient.a
	${INSTALL_DATA} ${WRKSRC}/sphinxclient.h ${PREFIX}/include/sphinxclient.h
	${LN} -s ${PREFIX}/lib/libsphinxclient-0.0.1.so ${PREFIX}/lib/libsphinxclient.so.0
	${LN} -s ${PREFIX}/lib/libsphinxclient-0.0.1.so ${PREFIX}/lib/libsphinxclient.so

.include <bsd.port.mk>
