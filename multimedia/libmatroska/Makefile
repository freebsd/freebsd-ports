# New ports collection makefile for:	libmatroska
# Date created:		Mon May 19 08:29:44 UTC 2003
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmatroska
PORTVERSION=	0.7.1
CATEGORIES=	multimedia audio
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/ \
		http://www.bunkus.org/videotools/mkvtoolnix/sources/old/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Extensible Multimedia Container Format

BUILD_DEPENDS=	${LOCALBASE}/lib/libebml.a:${PORTSDIR}/textproc/libebml

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
BUILD_WRKSRC=	${WRKSRC}/make/linux
INSTALL_WRKSRC=	${WRKSRC}/make/linux

# Installs dir with proper permissions
INSTALL_DATA_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755

post-patch:
# XXX - revise at every port update
# the tests are botched. do not run them
	@${REINPLACE_CMD} -E \
		-e 's|^(all:.*)test|\1|' \
		${WRKSRC}/make/linux/Makefile

do-configure:
	@${REINPLACE_CMD} -E \
		-e 's|^(prefix).*$$|\1=${PREFIX}|; \
			s,^(CXX|LD)[[:space:]]*=.*$$,\1=${CXX},; \
			s|^(CXXFLAGS)[[:space:]]*=(.*)$$|\1+=\2|; \
			s|^(LIBEBML_INCLUDE_DIR)[[:space:]]*=.*|\1=${LOCALBASE}/include|; \
			s|^(LIBEBML_LIB_DIR)[[:space:]]*=.*|\1=${LOCALBASE}/lib|; \
			s|^(INSTALL)[[:space:]]*=.*$$|\1=|; \
			s|^(INSTALL_DIR_OPTS)[[:space:]]*=.*$$|\1=${INSTALL_DATA_DIR}|; \
			s,^(INSTALL_OPTS_LIB|INSTALL_OPTS)[[:space:]]*=.*$$,\1=${INSTALL_DATA},' \
		${WRKSRC}/make/linux/Makefile

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
CFLAGS+= -DNO_WSTRING -I${LOCALBASE}/include
.endif

.include <bsd.port.post.mk>
