PORTNAME=	google-fonts
DISTVERSION=	0.0.0.20210120
CATEGORIES=	x11-fonts

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Collection of freely redistributable TrueType fonts from Google

LICENSE=	APACHE20 OFL11
LICENSE_COMB=	multi

RUN_DEPENDS=	Andika>0:x11-fonts/andika \
		GentiumBasic>0:x11-fonts/gentium-basic \
		alef>0:x11-fonts/alef \
		alegreya-sans>0:x11-fonts/alegreya-sans \
		anonymous-pro>0:x11-fonts/anonymous-pro \
		b612>0:x11-fonts/b612 \
		comfortaa-ttf>0:x11-fonts/comfortaa-ttf \
		comic-neue>0:x11-fonts/comic-neue \
		courier-prime>.:x11-fonts/courier-prime \
		croscorefonts>0:x11-fonts/croscorefonts-fonts-ttf \
		exo>0:x11-fonts/exo \
		fira>0:x11-fonts/fira \
		firacode>0:x11-fonts/firacode \
		jetbrains-mono>0:x11-fonts/jetbrains-mono \
		lato>.:x11-fonts/lato \
		montserrat>0:x11-fonts/montserrat \
		noto-basic>0:x11-fonts/noto-basic \
		open-sans>0:x11-fonts/open-sans \
		roboto-fonts-ttf>0:x11-fonts/roboto-fonts-ttf \
		sourcecodepro-ttf>0:x11-fonts/sourcecodepro-ttf \
		sourcesanspro-ttf>0:x11-fonts/sourcesanspro-ttf \
		sourceserifpro-ttf>0:x11-fonts/sourceserifpro-ttf \
		ubuntu-font>0:x11-fonts/ubuntu-font \
		vollkorn-ttf>0:x11-fonts/vollkorn-ttf

USES=		fonts

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	fonts
GH_TAGNAME=	88b06a0c39a81a8b6e5ecf7f1ba2ff9273d29167

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

# These font families are installed by the RUN_DEPENDS above.
EXCLUSIONS=	apache/arimo \
		apache/cousine \
		apache/opensans \
		apache/roboto \
		apache/tinos \
		ofl/alef \
		ofl/alegreyasans \
		ofl/alegreyasanssc \
		ofl/andika \
		ofl/anonymouspro \
		ofl/b612 \
		ofl/b612mono \
		ofl/comfortaa \
		ofl/comicneue \
		ofl/courierprime \
		ofl/exo2 \
		ofl/firacode \
		ofl/firamono \
		ofl/firasans \
		ofl/firasanscondensed \
		ofl/gentiumbasic \
		ofl/jetbrainsmono \
		ofl/lato \
		ofl/montserrat \
		ofl/montserratalternates \
		ofl/notonastaliqurdu \
		ofl/notomusic* \
		ofl/notosans* \
		ofl/notoserif* \
		ofl/nototraditionalnushu \
		ofl/sourcecodepro \
		ofl/sourcesanspro \
		ofl/sourceserifpro \
		ofl/vollkorn \
		ofl/vollkornsc \
		ufl/*

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} && ${RM} -r ${EXCLUSIONS})
	${FIND} ${WRKSRC} -name \*wght\* -delete
	${FIND} ${WRKSRC} -name \*.ttf -exec ${INSTALL_DATA} {} ${STAGEDIR}${FONTSDIR} \;

post-install-DOCS-on:
	for dir in $$(${FIND} ${WRKSRC} -name \*.ttf -exec ${DIRNAME} {} \; | ${SORT} -u); do \
		family=$$(${BASENAME} $${dir}); \
		${FIND} $${dir} \( -name \*.txt -o -name \*.html \) -exec \
			${SH} -c "${MKDIR} ${STAGEDIR}${DOCSDIR}/$${family} && \
			${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/$${family}" \; ; \
	done

.include <bsd.port.mk>
