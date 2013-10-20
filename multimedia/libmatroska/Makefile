# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmatroska
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/ \
		http://www.bunkus.org/videotools/mkvtoolnix/sources/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Extensible Multimedia Container Format

LICENSE=	LGPL21

LIB_DEPENDS=	libebml.so:${PORTSDIR}/textproc/libebml

USES=	gmake
USE_BZIP2=	yes
USE_DOS2UNIX=	make/linux/Makefile
BUILD_WRKSRC=	${WRKSRC}/make/linux
INSTALL_WRKSRC=	${WRKSRC}/make/linux
USE_LDCONFIG=	yes

# Installs dir with proper permissions
INSTALL_DATA_DIR=	${INSTALL} -d -m 755

MAKE_ARGS=	INSTALL_DIR_OPTS="${INSTALL} -d -m 755" \
		INSTALL_OPTS="${INSTALL_DATA}" \
		INSTALL_OPTS_LIB="${INSTALL_LIB}" \
		INSTALL="" \
		prefix=${PREFIX} \
		CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS}" \
		LIBEBML_INCLUDE_DIR="${LOCALBASE}/include" \
		LIBEBML_LIB_DIR="${LOCALBASE}/lib"

post-patch:
# XXX - revise at every port update
# the tests are botched. do not run them
	@${REINPLACE_CMD} -E \
		-e 's|^(all:.*)test|\1|' \
		${WRKSRC}/make/linux/Makefile

.include <bsd.port.mk>
