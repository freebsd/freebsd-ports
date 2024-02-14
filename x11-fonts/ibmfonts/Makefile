PORTNAME=	ibmfonts
DISTVERSION=	0.1
CATEGORIES=	x11-fonts

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	IBM Fonts in PCF format

LICENSE=	CC-BY-SA-4.0 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

USES=		fonts
FONTPATHSPEC=	${FONTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	farsil

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--bsd-make \
		--installdir=${FONTSDIR} \
		--prefix=${PREFIX}

NO_ARCH=	yes

OPTIONS_DEFINE=		VT100 XFTFIX
OPTIONS_DEFAULT=	VT100 XFTFIX
VT100_DESC=		Remove glyphs at 00-1F confusable for VT100 drawing
XFTFIX_DESC=		Fix Xft names removing repeated IBM in FAMILY_NAME

post-patch-VT100-on:
	@${REINPLACE_CMD} \
		-e 's/CHARS 782/CHARS 750/' -e 's/uni0000.*/space/' \
		-e '/ENCODING 0/,/STARTCHAR space/d' ${WRKSRC}/bdf/*.bdf

post-patch-XFTFIX-on:
	@${REINPLACE_CMD} \
		's/FAMILY_NAME "IBM /FAMILY_NAME "/' ${WRKSRC}/bdf/*.bdf

.include <bsd.port.mk>
