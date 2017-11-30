# $FreeBSD$

PORTNAME=	google-fonts
DISTVERSION=	0.0.0.20171112
CATEGORIES=	x11-fonts

MAINTAINER=	dg@syrec.org
COMMENT=	Collection of freely redistributable TrueType fonts from Google

LICENSE=	APACHE20 OFL11
LICENSE_COMB=	multi

RUN_DEPENDS=	anonymous-pro>0:x11-fonts/anonymous-pro \
		comfortaa-ttf>0:x11-fonts/comfortaa-ttf \
		croscorefonts>0:x11-fonts/croscorefonts-fonts-ttf \
		noto>0:x11-fonts/noto \
		roboto-fonts-ttf>0:x11-fonts/roboto-fonts-ttf \
		sourcecodepro-ttf>0:x11-fonts/sourcecodepro-ttf \
		sourcesanspro-ttf>0:x11-fonts/sourcesanspro-ttf \
		sourceserifpro-ttf>0:x11-fonts/sourceserifpro-ttf \
		ubuntu-font>0:x11-fonts/ubuntu-font \
		vollkorn-ttf>0:x11-fonts/vollkorn-ttf

USES=		fonts
NO_ARCH=	yes
NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	fonts
GH_TAGNAME=	a16b830

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

# These font families are installed by the RUN_DEPENDS above.
EXCLUSIONS=	ofl/anonymous-pro \
		ofl/comfortaa \
		apache/arimo \
		apache/cousine \
		apache/tinos \
		ofl/notosans \
		ofl/notosanstamil \
		ofl/notoserif \
		apache/roboto \
		apache/robotocondensed \
		ofl/sourcecodepro \
		ofl/sourcesanspro \
		ofl/sourceserifpro \
		ufl/* \
		ofl/vollkorn

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} && ${RM} -r ${EXCLUSIONS})
	${FIND} ${WRKSRC} -name \*.ttf -exec ${INSTALL_DATA} {} ${STAGEDIR}${FONTSDIR} \;

do-install-DOCS-on:
	for dir in $$(${FIND} ${WRKSRC} -name \*.ttf -exec ${DIRNAME} {} \; | ${SORT} -u); do \
		family=$$(basename $${dir}); \
		${MKDIR} ${STAGEDIR}${DOCSDIR}/$${family}; \
		${FIND} $${dir} \( -name \*.txt -o -name \*.html \) -exec \
			${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/$${family} \; ; \
	done

.include <bsd.port.mk>
