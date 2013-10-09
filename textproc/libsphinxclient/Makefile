# Created by: Max Baryshnikov <mephius@gmail.com>
# $FreeBSD$

PORTNAME=	libsphinxclient
DISTVERSION=	2.0.9
CATEGORIES=	textproc databases
MASTER_SITES=	http://sphinxsearch.com/files/
DISTNAME=	sphinx-${PORTVERSION}-release

MAINTAINER=	mephius@gmail.com
COMMENT=	Sphinx Full-Text Search Engine C++ client library

LICENSE=	GPLv2

WRKSRC_SUBDIR=	api/libsphinxclient

USE_LDCONFIG=	yes

USE_AUTOTOOLS=	libtool
MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CC=${CC}
SUB_LIST+=	PORTNAME=${PORTNAME}

do-install:
	${INSTALL_LIB} ${WRKSRC}/.libs/libsphinxclient-0.0.1.so ${STAGEDIR}${PREFIX}/lib/libsphinxclient-0.0.1.so
	${INSTALL_DATA} ${WRKSRC}/libsphinxclient.la ${STAGEDIR}${PREFIX}/lib/libsphinxclient.la
	${INSTALL_DATA} ${WRKSRC}/.libs/libsphinxclient.a ${STAGEDIR}${PREFIX}/lib/libsphinxclient.a
	${INSTALL_DATA} ${WRKSRC}/sphinxclient.h ${STAGEDIR}${PREFIX}/include/sphinxclient.h
	${LN} -s libsphinxclient-0.0.1.so ${STAGEDIR}${PREFIX}/lib/libsphinxclient.so.0
	${LN} -s libsphinxclient-0.0.1.so ${STAGEDIR}${PREFIX}/lib/libsphinxclient.so

.include <bsd.port.mk>
