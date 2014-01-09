# Created by: erich@FreeBSD.org
# $FreeBSD$

PORTNAME=	freefonts
PORTVERSION=	0.10
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.fh-heilbronn.de/mirrors/ftp.gimp.org/%SUBDIR%/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gimp/fonts

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Collection of ATM fonts (not all free) from the CICA archives

BUILD_DEPENDS=	type1inst:${PORTSDIR}/x11-fonts/p5-type1inst

RESTRICTED=	see accompanying .license files
NO_WRKSUBDIR=	yes

FONTDIR?=	${PREFIX}/lib/X11/fonts/freefont
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

do-build:
	@cd ${WRKSRC}/freefont && ${LOCALBASE}/bin/type1inst -silent -quiet -nolog >/dev/null 2>&1
	@${RM} ${WRKSRC}/freefont/Fontmap.bak

do-install:
	@${MKDIR} ${STAGEDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/freefont/* ${STAGEDIR}${FONTDIR}

.include <bsd.port.mk>
