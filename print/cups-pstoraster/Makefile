# New ports collection makefile for:	cups-pstoraster
# Date created:		Jul 13 2002
# Whom:			ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cups-pstoraster
PORTVERSION=	7.07
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.easysw.com/pub/ghostscript/
MASTER_SITE_SUBDIR=	ghostscript espgs
DISTFILES=	ghostscript-${PORTVERSION}${EXTRACT_SUFX} \
		espgs-${ESPGS_VER}-source${EXTRACT_SUFX}
DIST_SUBDIR=	ghostscript

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Postscript interpreter for CUPS printing to non-PS printers

BROKEN=		Changes ownership of previously installed files

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/${PORTVERSION}/lib/gs_init.ps:${PORTSDIR}/print/ghostscript-gnu

ESPGS_VER=	7.07.1
ESPGS_WRKSRC=	${WRKDIR}/espgs-${ESPGS_VER}/pstoraster
WRKSRC=		${WRKDIR}/ghostscript-${PORTVERSION}

USE_BZIP2=	yes
USE_REINPLACE=	yes
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
	${CHOWN} -R ${CUPSOWN}:${CUPSGRP} \
		${PREFIX}/etc/cups ${PREFIX}/libexec/cups/filter
.for file in pxlcolor.ppd pxlmono.ppd
	${INSTALL_DATA} ${ESPGS_WRKSRC}/${file} ${PREFIX}/share/cups/model
.endfor

.include "${.CURDIR}/../../print/cups/Makefile.common"
.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
