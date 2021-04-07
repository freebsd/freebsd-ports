PORTNAME=	powerline-fonts
PORTVERSION=	0.0.0.2020.08.28
CATEGORIES=	x11-fonts

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Fixed width sans fonts for use with powerline

USES=		fonts

USE_GITHUB=	yes
GH_ACCOUNT=	powerline
GH_PROJECT=	fonts
GH_TAGNAME=	e80e3eb

NO_ARCH=	yes
NO_BUILD=	yes

TTF_FONTS=	3270 AnonymousPro Arimo Cousine DejaVuSansMono \
		DroidSansMonoDotted DroidSansMonoSlashed GoMono Hack \
		Inconsolata LiberationMono Meslo\ Dotted Meslo\ Slashed Monofur \
		NotoMono NovaMono ProFont RobotoMono SpaceMono SymbolNeu Tinos \
		UbuntuMono
OTF_FONTS=	DroidSansMono FiraMono Inconsolata Inconsolata-g InconsolataDz \
		SourceCodePro
PCF_FONTS=	Terminus
DOCDIRS=	3270 AnonymousPro Arimo Cousine DejaVuSansMono DroidSansMono \
		DroidSansMonoDotted DroidSansMonoSlashed FiraMono GoMono Hack \
		Inconsolata Inconsolata-g InconsolataDz InputMono \
		LiberationMono Meslo\ Dotted Meslo\ Slashed NotoMono NovaMono \
		ProFont RobotoMono SourceCodePro SpaceMono SymbolNeu Terminus \
		Tinos UbuntuMono
LICDIRS=	AnonymousPro Arimo Cousine DejaVuSansMono DroidSansMono \
		DroidSansMonoDotted DroidSansMonoSlashed FiraMono Hack \
		Inconsolata Inconsolata-g InconsolataDz LiberationMono \
		Meslo\ Dotted Meslo\ Slashed Monofur NovaMono RobotoMono \
		SourceCodePro SpaceMono SymbolNeu Terminus Tinos

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
	${CP} ${WRKSRC}/NotoMono/LICENSE_OFL.txt ${STAGEDIR}${DOCSDIR}/LICENSE_NotoMono_OFL.txt
	${CP} ${WRKSRC}/ProFont/LICENSE ${STAGEDIR}${DOCSDIR}/LICENSE_ProFont.txt

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
