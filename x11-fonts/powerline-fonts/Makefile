# $FreeBSD$

PORTNAME=	powerline-fonts
PORTVERSION=	0.0.0.2015.12.04
CATEGORIES=	x11-fonts

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Fixed width sans fonts for use with powerline

USE_GITHUB=	yes
GH_ACCOUNT=	powerline
GH_PROJECT=	fonts
GH_TAGNAME=	2015-12-04

USES=		fonts
NO_BUILD=	yes

TTF_FONTS=	AnonymousPro Arimo Cousine DejaVuSansMono DroidSansMonoDotted \
		DroidSansMonoSlashed Hack LiberationMono Monofur RobotoMono \
		SymbolNeu Tinos UbuntuMono
OTF_FONTS=	DroidSansMono FiraMono Inconsolata Inconsolata-g InconsolataDz \
		Meslo SourceCodePro
PCF_FONTS=	Terminus
DOCDIRS=	AnonymousPro Arimo Cousine DejaVuSansMono DroidSansMonoDotted \
		DroidSansMonoSlashed Hack LiberationMono RobotoMono SymbolNeu \
		Tinos UbuntuMono DroidSansMono FiraMono Inconsolata \
		Inconsolata-g InconsolataDz Meslo SourceCodePro Terminus
LICDIRS=	AnonymousPro Arimo Cousine DejaVuSansMono DroidSansMonoDotted \
		DroidSansMonoSlashed Hack LiberationMono RobotoMono SymbolNeu \
		Tinos DroidSansMono FiraMono Inconsolata \
		Inconsolata-g InconsolataDz Meslo SourceCodePro Terminus

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for dir in ${DOCDIRS}
	${CP} ${WRKSRC}/${dir}/README.rst ${STAGEDIR}${DOCSDIR}/README_${dir}.rst
.endfor
.for dir in ${LICDIRS}
	${CP} ${WRKSRC}/${dir}/LICENSE.txt ${STAGEDIR}${DOCSDIR}/LICENSE_${dir}.txt
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.for font in ${OTF_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${font}/*.otf ${STAGEDIR}${FONTSDIR}
.endfor
.for font in ${TTF_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${font}/*.ttf ${STAGEDIR}${FONTSDIR}
.endfor
.for font in ${PCF_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${font}/PCF/*.pcf.gz ${STAGEDIR}${FONTSDIR}
.endfor

.include <bsd.port.mk>
