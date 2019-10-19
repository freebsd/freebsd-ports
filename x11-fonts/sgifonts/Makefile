# Created by: trevor
# $FreeBSD$

PORTNAME=	sgifonts
PORTVERSION=	1.0.1
PORTREVISION=	5
CATEGORIES=	x11-fonts
MASTER_SITES=	https://BSDforge.com/projects/source/x11-fonts/sgifonts/
DISTNAME=	sgi-fonts-1.0-1.src
EXTRACT_SUFX=	.rpm

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Fonts from the SGI ProPack 1.4 (originally for Linux)

LICENSE=	MIT

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

USES=		fonts
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message

FONTNAME=	sgi
PLIST_FILES=	${FONTS:S!^!${FONTSDIR}/!:S!$!.pcf.gz!} \
		${FONTSDIR}/fonts.alias

FONTS=		Scr7 Scr8 Scr9 Scr10 Scr11 Scr12 \
		Scr13 Scr14 Scr15 Scr16 Scr18 \
		ScrB7 ScrB8 ScrB9 ScrB10 ScrB11 ScrB12 \
		ScrB13 ScrB14 ScrB15 ScrB16 ScrB18 \
		haeberli12 haeberli24 haeberli36 \
		intl15 iris10 iris12 iris13 \
		rock12 rock18 rock24 rock36 \
		space10 type13

post-extract:
	@(cd ${WRKSRC} && ${TAR} ${EXTRACT_BEFORE_ARGS} \
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
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC}/sgi-fonts/sgi && ${INSTALL_DATA} fonts.alias \
		${STAGEDIR}${FONTSDIR})
	(cd ${WRKSRC}/sgi-fonts/sgi && ${INSTALL_DATA} *.pcf.gz \
		${STAGEDIR}${FONTSDIR})

.include <bsd.port.mk>
