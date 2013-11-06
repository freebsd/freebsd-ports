# Created by: Patrick Dung (patrick_dkt@yahoo.com.hk)
# $FreeBSD$

PORTNAME=	pdftk
PORTVERSION=	1.45
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.pdflabs.com/tools/pdftk-the-pdf-toolkit/ \
		LOCAL/glarkin
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Simple tool for doing everyday things with PDF documents

USE_ZIP=	yes

BUILD_DEPENDS=	gcj${CSUFF}:${PORTSDIR}/lang/gcc${CSUFF} \
		gcjh${CSUFF}:${PORTSDIR}/lang/gcc${CSUFF} \
		cpp${CSUFF}:${PORTSDIR}/lang/gcc${CSUFF}

# Get GCC version suffix without the dot in USE_GCC
CSUFF=		${_USE_GCC:S/.//}

USE_GCC=	yes
USE_GMAKE=	yes
USES=		iconv
USE_LDCONFIG=	${PREFIX}/lib/gcc${CSUFF}

# gcj/libgcj don't exist on some platforms
ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	GNU gcj does not exist on this platform

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}-dist
WRKSRC=		${PATCH_WRKSRC}/${PORTNAME}

MAKEFILE=	Makefile.FreeBSD
MAKE_ENV=	GCJ=gcj${CSUFF} GCJH=gcjh${CSUFF} GCPP=cpp${CSUFF} \
		OBJCOPY=${OBJCOPY} LANG=C LC_CTYPE=C

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e "s|TOOLPATH=|TOOLPATH=${LOCALBASE}/bin/|g" ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e "s|VERSUFF=|VERSUFF=${CSUFF}|g" ${WRKSRC}/${MAKEFILE}

#2005-10-29 - mjoyner@vbservices.net/mjoyner@ewc.edu
#as shipped, pdftk compiles fine with 3.4 gcj, as we currently only have 4.1 gcj available,
#fix things so that it will compile. (compile tested on 5.4-STABLE)
#
#The resulting binary from using the 4.1 compiler suite has *NOT* been regression tested!
#Based on info found via Google USENET Search: Adam McDougall, Gerald Pfeifer
#

	@${REINPLACE_CMD} -e "s|GCJFLAGS=|GCJFLAGS= -L${LOCALBASE}/lib -Wl,-rpath=${LOCALBASE}/lib/gcc${CSUFF} -w|g" ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e "s|LDLIBS= -lgcj|LDLIBS= -lgcj ${PTHREAD_CFLAGS} ${PTHREAD_LIBS} ${ICONV_LIB} -lz -L${LOCALBASE}/lib -Wl,-rpath=${LOCALBASE}/lib/gcc${CSUFF} -w|g" \
			${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
