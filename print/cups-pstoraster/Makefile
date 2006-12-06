# New ports collection makefile for:	cups-pstoraster
# Date created:		Jul 13 2002
# Whom:			ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cups-pstoraster
PORTVERSION=	8.15.3
CATEGORIES=	print
MASTER_SITES=	\
	ftp://ftp.rz.tu-bs.de/pub/mirror/ftp.easysw.com/ftp/pub/%SUBDIR%/ \
	ftp://ftp2.easysw.com/pub/%SUBDIR%/ \
	ftp://ftp3.easysw.com/pub/%SUBDIR%/ \
	http://ftp.easysw.com/pub/%SUBDIR%/ \
	http://ftp.rz.tu-bs.de/pub/mirror/ftp.easysw.com/ftp/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	ghostscript/${PORTVERSION}
DIST_SUBDIR=	ghostscript

MAINTAINER=	frank@exit.com
COMMENT=	Postscript interpreter for CUPS printing to non-PS printers

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base

ESPGS_VER=	${PORTVERSION}
GS_VERSION=	8.15

DISTNAME=	espgs-${ESPGS_VER}-source
WRKSRC=		${WRKDIR}/espgs-${PORTVERSION}

DATADIR=	${TARGETDIR}/share/ghostscript

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-x --with-gs=espgs
MAKE_ARGS=	CFLAGS_STANDARD="${CFLAGS} -DUPD_SIGNAL=0" \
		DEVICE_DEVS="\$$(DD)cups.dev \$$(DD)pxlcolor.dev \$$(DD)pxlmono.dev"
PLIST_SUB=	GS_VERSION="${GS_VERSION}"
PLIST_FILES=	bin/espgs etc/cups/pstoraster.convs \
		libexec/cups/filter/pstopxl libexec/cups/filter/pstoraster \
		share/cups/model/pxlcolor.ppd share/cups/model/pxlmono.ppd

.ifdef(WITH_GHOSTSCRIPT_AFPL)
IGNORE=		doesn't build with AFPL version of Ghostscript; please use gnu ghostscript instead
.endif

pre-configure:
	${RM} -f ${WRKSRC}/ijs/config.guess ${WRKSRC}/ijs/missing ${WRKSRC}/ijs/config.sub ${WRKSRC}/ijs/install-sh ${WRKSRC}/ijs/ltmain.sh
	${RM} -f ${WRKSRC}/trunk/ijs/config.guess ${WRKSRC}/trunk/ijs/missing ${WRKSRC}/trunk/ijs/config.sub ${WRKSRC}/trunk/ijs/install-sh ${WRKSRC}/trunk/ijs/ltmain.sh

post-patch:
	${LN} -sf ${WRKSRC}/pstoraster/gdevcups.c ${WRKSRC}/src
	${CAT} ${FILESDIR}/cups.contrib.mak >> ${WRKSRC}/src/contrib.mak
.for file in pstopxl pstoraster
	${SED} -e 's:@prefix@:${PREFIX}:g ; \
		 s:@exec_prefix@:${PREFIX}:g ; \
		 s:@bindir@:${PREFIX}/bin:g ; \
		 s:@GS@:espgs:g' \
		${WRKSRC}/pstoraster/${file}.in > ${WRKSRC}/pstoraster/${file}
.endfor
	${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS=@CPPFLAGS@ |g ; \
		 s|^LDFLAGS=|LDFLAGS=@LDFLAGS@ |g ; \
		 s|^DEVICE_DEVS|#DEVICE_DEVS|g' ${WRKSRC}/Makefile.in

pre-build:
	${MKDIR} ${WRKSRC}/bin
	${MKDIR} ${WRKSRC}/obj

.include <bsd.port.mk>
