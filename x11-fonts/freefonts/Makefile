# New ports collection makefile for:    freefonts
# Date created:         Thu Aug  1 21:32:14 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	freefonts
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.fh-heilbronn.de/mirrors/ftp.gimp.org/%SUBDIR%/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gimp/fonts

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A collection of ATM fonts (not all free) from the CICA archives

BUILD_DEPENDS=	type1inst:${PORTSDIR}/x11-fonts/p5-type1inst

RESTRICTED=	"see accompanying .license files"
NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

do-build:
	@cd ${WRKSRC}/freefont && ${LOCALBASE}/bin/type1inst -silent -quiet -nolog >/dev/null 2>&1
	@${RM} ${WRKSRC}/freefont/Fontmap.bak

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/freefont
	@${INSTALL_DATA} ${WRKSRC}/freefont/* ${PREFIX}/lib/X11/fonts/freefont

post-install:
	@${CAT} ${DESCR}

.include <bsd.port.mk>
