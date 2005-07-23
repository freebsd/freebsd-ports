# Ports collection makefile for:	pdftk
# Date created:			18 March, 2004
# Whom:				Patrick Dung (patrick_dkt@yahoo.com.hk)
#
# $FreeBSD$
#

PORTNAME=	pdftk
PORTVERSION=	1.12
CATEGORIES=	print
MASTER_SITES=	http://www.pdfhacks.com/pdftk/ \
		http://www.accesspdf.com/pdftk/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}.${PORTVERSION:E}

MAINTAINER=	patrick_dkt@yahoo.com.hk
COMMENT=	A simple tool for doing everyday things with PDF documents

# gcj/libgcj don't exist on these platforms
NOT_FOR_ARCHS=	amd64 ia64 sparc64

BROKEN=		"Broken dependency"
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

# Get gcc version suffix without the dot in USE_GCC
CSUFF=		${USE_GCC:S/.//}

# needs gcj
BUILD_DEPENDS=	gcj${CSUFF}:${PORTSDIR}/lang/gcc${CSUFF}

USE_GCC=	3.4
USE_GMAKE=	yes
USE_ICONV=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

MAKEFILE=	Makefile.Generic
MAKE_ENV=	GCJ=gcj${CSUFF} GCJH=gcjh${CSUFF}

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/pdftk

post-extract:
	@${REINPLACE_CMD} -e "s|TOOLPATH=|TOOLPATH=${LOCALBASE}/bin/|g" ${WRKSRC}/Makefile.Generic
	@${REINPLACE_CMD} -e "s|VERSUFF=|VERSUFF=${CSUFF}|g" ${WRKSRC}/Makefile.Generic
	@${REINPLACE_CMD} -e "s|CXXFLAGS= -lgcj|CXXFLAGS= -lgcj ${PTHREAD_CFLAGS} ${PTHREAD_LIBS} -liconv -lz|g" ${WRKSRC}/Makefile.Generic

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../debian/${PORTNAME}.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
