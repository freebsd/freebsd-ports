# New ports collection makefile for:	cups-pstoraster
# Date created:		Jul 13 2002
# Whom:			ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cups-pstoraster
PORTVERSION=	7.07
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.easysw.com/pub/ghostscript/
MASTER_SITE_SUBDIR=	ghostscript espgs
DISTFILES=	ghostscript-${PORTVERSION}${EXTRACT_SUFX} \
		espgs-7.05.6-source${EXTRACT_SUFX}
DIST_SUBDIR=	ghostscript

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Postscript interpreter for CUPS printing to non-PS printers

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/${PORTVERSION}/lib/gs_init.ps:${PORTSDIR}/print/ghostscript-gnu

WRKSRC=		${WRKDIR}/ghostscript-${PORTVERSION}

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-x --without-ijs --without-gimp-print \
		--with-gs=espgs
MAKE_ARGS=	CFLAGS_STANDARD="${CFLAGS} -DUPD_SIGNAL=0" \
		DEVICE_DEVS="\$$(DD)cups.dev"

ESPGS_WRKSRC=	${WRKDIR}/espgs-7.05.6/pstoraster

post-patch:
	${LN} -sf ${ESPGS_WRKSRC}/gdevcups.c ${WRKSRC}/src
	${CAT} ${FILESDIR}/cups.contrib.mak >> ${WRKSRC}/src/contrib.mak
	${SED} -e 's:@prefix@:${PREFIX}:g ; \
		 s:@exec_prefix@:${PREFIX}:g ; \
		 s:@bindir@:${PREFIX}/bin:g ; \
		 s:@GS@:espgs:g' \
		${ESPGS_WRKSRC}/pstoraster.in > ${ESPGS_WRKSRC}/pstoraster
	${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS=@CPPFLAGS@ |g ; \
		 s|^LDFLAGS=|LDFLAGS=@LDFLAGS@ |g ; \
		 s|^DEVICE_DEVS|#DEVICE_DEVS|g' ${WRKSRC}/Makefile.in

pre-build:
	${MKDIR} ${WRKSRC}/bin
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/espgs ${PREFIX}/bin
	${INSTALL_DATA} ${ESPGS_WRKSRC}/pstoraster.convs \
		${PREFIX}/etc/cups
	${INSTALL_SCRIPT} ${ESPGS_WRKSRC}/pstoraster \
		${PREFIX}/libexec/cups/filter
	${CHOWN} -R ${CUPSOWN}:${CUPSGRP} \
		${PREFIX}/etc/cups ${PREFIX}/libexec/cups/filter

.include "${.CURDIR}/../../print/cups/Makefile.common"
.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
