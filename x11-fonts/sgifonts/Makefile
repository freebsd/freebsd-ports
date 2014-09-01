# Created by: trevor
# $FreeBSD$

PORTNAME=	sgifonts
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://patches.sgi.com/pub/linux/ProPack1.4/SRPMS/
DISTNAME=	sgi-fonts-1.0-1.src
EXTRACT_SUFX=	.rpm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fonts from the SGI ProPack 1.4 (originally for Linux)

LICENSE=	MIT

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

NO_ARCH=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message

PLIST_FILES=	lib/X11/fonts/local/sgi/fonts.alias \
		lib/X11/fonts/local/sgi/fonts.dir \
		${FONTS:S!^!lib/X11/fonts/local/sgi/!:S!$!.pcf.gz!}
PLIST_DIRS=	lib/X11/fonts/local/sgi

FONTS=		Scr7 Scr8 Scr9 Scr10 Scr11 Scr12 \
		Scr13 Scr14 Scr15 Scr16 Scr18 \
		ScrB7 ScrB8 ScrB9 ScrB10 ScrB11 ScrB12 \
		ScrB13 ScrB14 ScrB15 ScrB16 ScrB18 \
		haeberli12 haeberli24 haeberli36 \
		intl15 iris10 iris12 iris13 \
		rock12 rock18 rock24 rock36 \
		space10 type13

post-extract:
	@(cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		sgi-fonts.tar.gz ${EXTRACT_AFTER_ARGS})

post-patch:
	@${FIND} ${WRKSRC}/sgi-fonts/sgi -name "*.bdf" | ${XARGS} \
		${REINPLACE_CMD} -e \
		'/^FOUNDRY/s|""|"SGI"|'

do-build:
.for i in ${FONTS}
	(cd ${WRKSRC}/sgi-fonts/sgi \
		&& bdftopcf ${i}.bdf | ${GZIP_CMD} > ${i}.pcf.gz)
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/fonts/local/sgi
	(cd ${WRKSRC}/sgi-fonts/sgi && ${INSTALL_DATA} fonts.alias \
		${STAGEDIR}${PREFIX}/lib/X11/fonts/local/sgi)
	(cd ${WRKSRC}/sgi-fonts/sgi && ${INSTALL_DATA} *.pcf.gz \
		${STAGEDIR}${PREFIX}/lib/X11/fonts/local/sgi)
	(cd ${STAGEDIR}${PREFIX}/lib/X11/fonts/local/sgi && mkfontdir)

.include <bsd.port.mk>
