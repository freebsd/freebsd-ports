# Ports collection makefile for:	pdftk
# Date created:			18 March, 2004
# Whom:				Patrick Dung (patrick_dkt@yahoo.com.hk)
#
# $FreeBSD$
#

PORTNAME=	pdftk
PORTVERSION=	0.94.1
CATEGORIES=	print
MASTER_SITES=	http://www.accesspdf.com/pdftk/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	patrick_dkt@yahoo.com.hk
COMMENT=	A simple tool for doing everyday things with PDF documents

# needs gcj
BUILD_DEPENDS=	gcj33:${PORTSDIR}/lang/gcc33

# gcj don't exist on
NOT_FOR_ARCHS=	ia64 sparc64

USE_GCC=	3.3
USE_GMAKE=	yes
USE_ICONV=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

MAKEFILE=	Makefile.Generic
MAKE_ENV=	CXX=g++33 GCJ=gcj33 GCJH=gcjh33

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/pdftk

post-extract:
	@${REINPLACE_CMD} -e "s|CXXFLAGS \+\=|CXXFLAGS \+\= ${PTHREAD_CFLAGS} ${PTHREAD_LIBS} -liconv -lz|g" ${WRKSRC}/Makefile.Base
	@${REINPLACE_CMD} -e "s|g\+\+|g\+\+33|g" ${WRKSRC}/Makefile.Generic
	@${REINPLACE_CMD} -e "s|MAKE)|MAKE) GXX=g++33 GCJ=gcj33 GCJH=gcjh33| " ${WRKSRC}/Makefile.Base

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../debian/${PORTNAME}.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
