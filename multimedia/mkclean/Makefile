# New ports collection makefile for:	mkclean
# Date created:		2010-10-24
# Whom:			Peter Johnson <johnson.peter@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mkclean
PORTVERSION=	0.6.0
CATEGORIES=	multimedia
MASTER_SITES=	SF/matroska/${PORTNAME}

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	Clean and optimize Matroska and WebM files

USE_BZIP2=	yes
USE_ICONV=	yes
USE_GMAKE=	yes

HAS_CONFIGURE=	yes
MAKE_ENV+=	CCFLAGS="-I${LOCALBASE}/include" \
		LFLAGS="-L${LOCALBASE}/lib -liconv"

MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/mkclean bin/mkWDclean bin/mkvtree

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/*/mkclean ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/release/*/mkWDclean ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/release/*/mkvtree ${PREFIX}/bin

.include <bsd.port.mk>
