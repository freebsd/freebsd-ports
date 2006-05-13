# New ports collection makefile for:	cups-pstoraster
# Date created:		Jul 13 2002
# Whom:			ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cups-pstoraster
PORTVERSION=	8.15
CATEGORIES=	print
MASTER_SITES=	\
	ftp://ftp.rz.tu-bs.de/pub/mirror/ftp.easysw.com/ftp/pub/%SUBDIR%/ \
	ftp://ftp2.easysw.com/pub/%SUBDIR%/ \
	ftp://ftp3.easysw.com/pub/%SUBDIR%/ \
	http://ftp.easysw.com/pub/%SUBDIR%/ \
	http://ftp.rz.tu-bs.de/pub/mirror/ftp.easysw.com/ftp/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	ghostscript/test
DIST_SUBDIR=	ghostscript

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Postscript interpreter for CUPS printing to non-PS printers

PATCH_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/${GHOSTSCRIPT_PORT}:patch
LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base

ESPGS_VER=	${PORTVERSION}rc3

DISTNAME=	espgs-${ESPGS_VER}-source
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - espgs-${ESPGS_VER}/pstoraster
ESPGS_WRKSRC=	${WRKDIR}/espgs-${ESPGS_VER}/pstoraster
WRKSRC=		${WRKDIRPREFIX}$$(${REALPATH} ${PORTSDIR})/${GHOSTSCRIPT_PORT}/work/ghostscript
PATCH_WRKSRC=	${ESPGS_WRKSRC}

USE_BZIP2=	yes
USE_GHOSTSCRIPT_RUN=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-x --without-ijs --without-gimp-print \
		--with-gs=espgs
MAKE_ARGS=	CFLAGS_STANDARD="${CFLAGS} -DUPD_SIGNAL=0" \
		DEVICE_DEVS="\$$(DD)cups.dev \$$(DD)pxlcolor.dev \$$(DD)pxlmono.dev"

PLIST_FILES=	bin/espgs etc/cups/pstoraster.convs \
		libexec/cups/filter/pstopxl libexec/cups/filter/pstoraster \
		share/cups/model/pxlcolor.ppd share/cups/model/pxlmono.ppd

post-patch:
	${LN} -sf ${ESPGS_WRKSRC}/gdevcups.c ${WRKSRC}/src
	${CAT} ${FILESDIR}/cups.contrib.mak >> ${WRKSRC}/src/contrib.mak
.for file in pstopxl pstoraster
	${SED} -e 's:@prefix@:${PREFIX}:g ; \
		 s:@exec_prefix@:${PREFIX}:g ; \
		 s:@bindir@:${PREFIX}/bin:g ; \
		 s:@GS@:espgs:g' \
		${ESPGS_WRKSRC}/${file}.in > ${ESPGS_WRKSRC}/${file}
.endfor
	${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS=@CPPFLAGS@ |g ; \
		 s|^LDFLAGS=|LDFLAGS=@LDFLAGS@ |g ; \
		 s|^DEVICE_DEVS|#DEVICE_DEVS|g' ${WRKSRC}/Makefile.in

pre-build:
	${MKDIR} ${WRKSRC}/bin
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/espgs ${PREFIX}/bin
	${INSTALL_DATA} ${ESPGS_WRKSRC}/pstoraster.convs ${PREFIX}/etc/cups
.for file in pstopxl pstoraster
	${INSTALL_SCRIPT} ${ESPGS_WRKSRC}/${file} ${PREFIX}/libexec/cups/filter
.endfor
.for file in pxlcolor.ppd pxlmono.ppd
	${INSTALL_DATA} ${ESPGS_WRKSRC}/${file} ${PREFIX}/share/cups/model
.endfor

.include <bsd.port.mk>
