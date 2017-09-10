# Created by: Patrick Dung (patrick_dkt@yahoo.com.hk)
# $FreeBSD$

PORTNAME=	pdftk
PORTVERSION=	2.02
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	http://www.pdflabs.com/tools/pdftk-the-pdf-toolkit/ LOCAL/mat/pdftk
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Simple tool for doing everyday things with PDF documents

LICENSE=	GPLv2

# Get GCC version suffix without the dot in USE_GCC
CSUFF=		${_USE_GCC:S/.//}

USE_GCC=	yes
USES=		iconv gmake zip

# gcj/libgcj don't exist on some platforms
ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	GNU gcj does not exist on this platform

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}-dist
WRKSRC=		${PATCH_WRKSRC}/${PORTNAME}

MAKEFILE=	Makefile.FreeBSD
MAKE_ENV=	GCJ=gcj${CSUFF} GCJH=gcjh${CSUFF} GCPP=cpp${CSUFF} \
		OBJCOPY=${OBJCOPY}

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

pre-configure:
	@if [ ! -e ${LOCALBASE}/bin/gcj${CSUFF} ]; then \
		${ECHO_MSG} ""; \
		${ECHO_MSG} "Can not find gcj${CSUFF}"; \
		${ECHO_MSG} "Please rebuild ${_GCC_PORT} with java support"; \
		${ECHO_MSG} ""; \
		exit 1; \
	fi

post-patch:
	@${REINPLACE_CMD} -e "s|TOOLPATH=|TOOLPATH=${LOCALBASE}/bin/|g; \
		s|VERSUFF=|VERSUFF=${CSUFF}|g; s|GCJFLAGS=|GCJFLAGS= -L${LOCALBASE}/lib ${LDFLAGS} -w|g; \
		s|LDLIBS= -lgcj|LDLIBS= -lgcj -pthread ${ICONV_LIB} -lz -L${LOCALBASE}/lib ${LDFLAGS} -w|g" \
		${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
