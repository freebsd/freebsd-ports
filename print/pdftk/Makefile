# Ports collection makefile for:	pdftk
# Date created:			18 March, 2004
# Whom:				Patrick Dung (patrick_dkt@yahoo.com.hk)
#
# $FreeBSD$
#

PORTNAME=	pdftk
PORTVERSION=	1.44
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.pdflabs.com/tools/pdftk-the-pdf-toolkit/ \
		LOCAL/glarkin
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A simple tool for doing everyday things with PDF documents

USE_ZIP=	yes

# Get gcc version suffix without the dot in USE_GCC
CSUFF=		${_USE_GCC:S/.//}

USE_GCC=	4.6+
USE_GMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	${PREFIX}/lib/gcc${CSUFF}

# gcj/libgcj don't exist on some platforms
ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	GNU gcj does not exist on this platform

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}-dist
WRKSRC=		${PATCH_WRKSRC}/${PORTNAME}

MAKEFILE=	Makefile.FreeBSD
MAKE_ENV=	GCJ=gcj${CSUFF} GCJH=gcjh${CSUFF} OBJCOPY=${OBJCOPY} LANG=C

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/pdftk

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
	@${REINPLACE_CMD} -e "s|LDLIBS= -lgcj|LDLIBS= -lgcj ${PTHREAD_CFLAGS} ${PTHREAD_LIBS} -liconv -lz -L${LOCALBASE}/lib -Wl,-rpath=${LOCALBASE}/lib/gcc${CSUFF} -w|g" \
			${WRKSRC}/${MAKEFILE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/../${PORTNAME}.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
