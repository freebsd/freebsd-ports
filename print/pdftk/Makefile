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

# Get gcc version suffix without the dot in USE_GCC
CSUFF=		${USE_GCC:S/.//}

# needs gcj
BUILD_DEPENDS=	gcj${CSUFF}:${PORTSDIR}/lang/gcc${CSUFF}

USE_GCC=	4.1
USE_GMAKE=	yes
USE_ICONV=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

MAKEFILE=	Makefile.Generic
MAKE_ENV=	GCJ=gcj${CSUFF} GCJH=gcjh${CSUFF}

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/pdftk

post-extract:
	@${REINPLACE_CMD} -e "s|TOOLPATH=|TOOLPATH=${LOCALBASE}/bin/|g" ${WRKSRC}/Makefile.Generic
	@${REINPLACE_CMD} -e "s|VERSUFF=|VERSUFF=${CSUFF}|g" ${WRKSRC}/Makefile.Generic

#2005-10-29 - mjoyner@vbservices.net/mjoyner@ewc.edu
#as shipped, pdftk compiles fine with 3.4 gcj, as we currently only have 4.1 gcj available,
#fix things so that it will compile. (compile tested on 5.4-STABLE)
#
#The resulting binary from using the 4.1 compiler suite has *NOT* been regression tested!
#Based on info found via Google USENET Search: Adam McDougall, Gerald Pfeifer
#

	@${REINPLACE_CMD} -e "s|GCJFLAGS=|GCJFLAGS= -L${LOCALBASE}/lib|g" ${WRKSRC}/Makefile.Generic
	@${REINPLACE_CMD} -e "s|CXXFLAGS= -lgcj|CXXFLAGS= -lgcj ${PTHREAD_CFLAGS} ${PTHREAD_LIBS} -liconv -lz -L${LOCALBASE}/lib|g" \
			${WRKSRC}/Makefile.Generic
	@${REINPLACE_CMD} -e "s|//SID import com.lowagie.text.ImgRaw;|import com.lowagie.text.ImgRaw;|g" \
			${WRKSRC}/../java_libs/com/lowagie/text/pdf/codec/PngImage.java
	@${REINPLACE_CMD} -e "s|^..java_libs_root./gnu/gcj/convert/convert.a|# x-nay the convert.a|g" ${WRKSRC}/Makefile.Base
	@${REINPLACE_CMD} -e "s|^..java_libs_root./gnu_local/java/security/security.a .|$$\(java_libs_root\)/gnu_local/java/security/security.a|g" ${WRKSRC}/Makefile.Base

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../debian/${PORTNAME}.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
