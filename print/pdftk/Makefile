# Ports collection makefile for:	pdftk
# Date created:			18 March, 2004
# Whom:				Patrick Dung (patrick_dkt@yahoo.com.hk)
#
# $FreeBSD$
#

PORTNAME=	pdftk
PORTVERSION=	1.41
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://www.pdfhacks.com/pdftk/ \
		http://www.accesspdf.com/pdftk/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}.${PORTVERSION:E}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A simple tool for doing everyday things with PDF documents

# Make this explicit for all OS versions.  For __FreeBSD_version < 700042,
# we need to build gcc 4.2 to get gcj42, and for OS versions with gcc 4.2+
# in the base system, we need to build the port anyway to get gcj42.
BUILD_DEPENDS=	gcj${CSUFF}:${PORTSDIR}/lang/gcc${CSUFF}

# Get gcc version suffix without the dot in USE_GCC
CSUFF=		${_USE_GCC:S/.//}

USE_GCC=	4.5+
USE_GMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	${PREFIX}/lib/gcc${CSUFF}

# gcj/libgcj don't exist on some platforms
ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	GNU gcj does not exist on this platform

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}

MAKEFILE=	Makefile.Generic
MAKE_ENV=	GCJ=gcj${CSUFF} GCJH=gcjh${CSUFF} OBJCOPY=${OBJCOPY} LANG=C

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

	@${REINPLACE_CMD} -e "s|GCJFLAGS=|GCJFLAGS= -L${LOCALBASE}/lib -Wl,-rpath=${LOCALBASE}/lib/gcc${CSUFF} -w|g" ${WRKSRC}/Makefile.Generic
	@${REINPLACE_CMD} -e "s|CXXFLAGS= -lgcj|CXXFLAGS= -lgcj ${PTHREAD_CFLAGS} ${PTHREAD_LIBS} -liconv -lz -L${LOCALBASE}/lib -Wl,-rpath=${LOCALBASE}/lib/gcc${CSUFF} -w|g" \
			${WRKSRC}/Makefile.Generic
	@${REINPLACE_CMD} -e "s|//SID import com.lowagie.text.ImgRaw;|import com.lowagie.text.ImgRaw;|g" \
			${WRKSRC}/../java_libs/com/lowagie/text/pdf/codec/PngImage.java
	@${REINPLACE_CMD} -e "s|^..java_libs_root./gnu/gcj/convert/convert.a|# x-nay the convert.a|g" ${WRKSRC}/Makefile.Base
	@${REINPLACE_CMD} -e "s|^..java_libs_root./gnu_local/java/security/security.a .|$$\(java_libs_root\)/gnu_local/java/security/security.a|g" ${WRKSRC}/Makefile.Base

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../debian/${PORTNAME}.1 ${PREFIX}/man/man1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=	gcjh45 core dumps on 6.x
.endif

.include <bsd.port.post.mk>
