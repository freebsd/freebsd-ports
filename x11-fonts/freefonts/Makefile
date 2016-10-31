# Created by: erich@FreeBSD.org
# $FreeBSD$

PORTNAME=	freefonts
PORTVERSION=	0.10
PORTREVISION=	8
CATEGORIES=	x11-fonts
MASTER_SITES=	http://download.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.sunet.se/pub/gnu/%SUBDIR%/   \
		http://ftp.gwdg.de/pub/misc/grafik/gimp/%SUBDIR%/ \
		http://mirrors.xmission.com/gimp/%SUBDIR%/
MASTER_SITE_SUBDIR=	gimp/fonts

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Collection of ATM fonts (not all free) from the CICA archives

BUILD_DEPENDS=	type1inst:x11-fonts/p5-type1inst

NO_ARCH=	yes
SUB_FILES=	pkg-message
USES=		fonts

# Some of the fonts are shareware. Some are freeware. Permission must
# be obtained before distributing at least four (mazama.license,
# muriel.license, roosthea.license, shf_____.license). Two have
# inconsistent licenses (tempofon.license and tempoita.license say
# "placed into the public domain and may [not be] sold")

RESTRICTED=	License prohibits redistribution; see individual .license files

NO_WRKSUBDIR=	yes

do-build:
	@cd ${WRKSRC}/freefont && ${LOCALBASE}/bin/type1inst -silent -quiet -nolog >/dev/null 2>&1
	@${RM} ${WRKSRC}/freefont/Fontmap.bak

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/freefont/* ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
