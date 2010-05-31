# New ports collection makefile for:	libmatroska
# Date created:		Mon May 19 08:29:44 UTC 2003
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmatroska
PORTVERSION=	0.9.0
CATEGORIES=	multimedia audio
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/ \
		http://www.bunkus.org/videotools/mkvtoolnix/sources/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Extensible Multimedia Container Format

LIB_DEPENDS=	ebml.0:${PORTSDIR}/textproc/libebml

USE_BZIP2=	yes
USE_GMAKE=	yes
BUILD_WRKSRC=	${WRKSRC}/make/linux
INSTALL_WRKSRC=	${WRKSRC}/make/linux
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

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
			s,^(INSTALL_OPTS_LIB|INSTALL_OPTS)[[:space:]]*=.*$$,\1=${INSTALL_DATA},; \
			/install:/s|install_staticlib||;/all:/s|staticlib||; \
			s,(-lebml)$$,-L${LOCALBASE}/lib \1,' \
		${WRKSRC}/make/linux/Makefile

.include <bsd.port.mk>
