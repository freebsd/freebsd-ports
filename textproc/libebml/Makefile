# New ports collection makefile for:	libebml
# Date created:		Mon May 19 08:29:44 UTC 2003
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libebml
PORTVERSION=	0.6.4
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://dl.matroska.org/downloads/libebml/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	EBML (Extensible Binary Meta Language), sort of binary version of XML

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_SIZE=	yes
BUILD_WRKSRC=	${WRKSRC}/make/linux
INSTALL_WRKSRC=	${WRKSRC}/make/linux

# Installs dir with proper permissions
INSTALL_DATA_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755

do-configure:
	@${REINPLACE_CMD} -E \
		-e 's|^(prefix)[[:space:]]*=.*$$|\1=${PREFIX}|; \
			s,^(CXX|LD)[[:space:]]*=.*$$,\1=${CXX},; \
			s|^(CXXFLAGS)[[:space:]]*=(.*)$$|\1+=\2|; \
			s|^(INSTALL)[[:space:]]*=.*$$|\1=|; \
			s|^(INSTALL_DIR_OPTS)[[:space:]]*=.*$$|\1=${INSTALL_DATA_DIR}|; \
			s,^(INSTALL_OPTS_LIB|INSTALL_OPTS)[[:space:]]*=.*$$,\1=${INSTALL_DATA},' \
		${WRKSRC}/make/linux/Makefile

.include <bsd.port.pre.mk>

# gcc 3.2 was available on 5.x before this OSVERSION
# do not build gcc 3.3 unless necessary
.if ${OSVERSION} < 501103
# use gcc 3.2
USE_GCC=3.2
.else
# default for 5.x series
USE_GCC=3.3
.endif

.if ${OSVERSION} < 500000
USE_GCC=2.95
# this is gcc 2.x
CFLAGS+= -DNO_WSTRING
.endif

.include <bsd.port.post.mk>
