PORTNAME=	libsphinxclient
DISTVERSION=	2.0.9
PORTREVISION=	1
CATEGORIES=	textproc databases
MASTER_SITES=	http://sphinxsearch.com/files/
DISTNAME=	sphinx-${PORTVERSION}-release

MAINTAINER=	mephius@gmail.com
COMMENT=	Sphinx Full-Text Search Engine C++ client library

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC_SUBDIR=	api/libsphinxclient

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

post-install:
	${LN} -s libsphinxclient-0.0.1.so ${STAGEDIR}${PREFIX}/lib/libsphinxclient-0.0.1.so.0

.include <bsd.port.mk>
