# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libebml
PORTVERSION=	1.3.0
CATEGORIES=	textproc
MASTER_SITES=	http://dl.matroska.org/downloads/libebml/ \
		http://www.bunkus.org/videotools/mkvtoolnix/sources/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	EBML (Extensible Binary Meta Language), sort of binary version of XML

LICENSE=	LGPL21

USES=		gmake
USE_BZIP2=	yes
BUILD_WRKSRC=	${WRKSRC}/make/linux
INSTALL_WRKSRC=	${WRKSRC}/make/linux
USE_LDCONFIG=	yes

MAKE_ARGS=	INSTALL_DIR_OPTS="${INSTALL} -d -m 755" \
		INSTALL_OPTS="${INSTALL_DATA}" \
		INSTALL_OPTS_LIB="${INSTALL_LIB}" \
		INSTALL="" \
		prefix=${STAGEDIR}${PREFIX} \
		CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS}"

.include <bsd.port.mk>
