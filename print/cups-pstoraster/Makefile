# New ports collection makefile for:	cups-pstoraster
# Date created:		Jul 13 2002
# Whom:			ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cups-pstoraster
PORTVERSION=	7.05.5
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.easysw.com/pub/ghostscript/
MASTER_SITE_SUBDIR=	espgs
DISTNAME=		espgs-${PORTVERSION}-source

MAINTAINER=	alane@FreeBSD.org

LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
RUN_DEPENDS+=	${LOCALBASE}/share/ghostscript/fonts/fonts.scale:${PORTSDIR}/print/ghostscript-gnu

WRKSRC=		${WRKDIR}/espgs-${PORTVERSION}

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-x --without-ijs --without-gimp-print \
		--with-drivers=cups --with-gs=espgs \
		--with-fontpath=${LOCALBASE}/share/ghostscript/fonts \
		--enable-compiled-inits --without-omni

USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${LOCALBASE}/share/ghostscript|g' \
		${WRKSRC}/lib/gs_res.ps

pre-build:
	${MKDIR} ${WRKSRC}/bin
	${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/espgs ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/pstoraster/pstoraster.convs \
		${PREFIX}/etc/cups
	${INSTALL_SCRIPT} ${WRKSRC}/pstoraster/pstoraster \
		${PREFIX}/libexec/cups/filter
	${CHOWN} -R ${CUPSOWN}:${CUPSGRP} \
		${PREFIX}/etc/cups ${PREFIX}/libexec/cups/filter

.include "${.CURDIR}/../../print/cups/Makefile.common"
.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
