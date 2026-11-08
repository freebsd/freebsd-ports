PORTNAME=	ia-writer-fonts
DISTVERSION=	20230616
CATEGORIES=	x11-fonts

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Typefaces of iA Writer: Mono, Duo, Quattro and Duospace
WWW=		https://github.com/iaolo/iA-Fonts

LICENSE=	OFL11

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	iaolo
GH_PROJECT=	iA-Fonts
GH_TAGNAME=	f32c04c3058a75d7ce28919ce70fe8800817491b
# Duospace was dropped upstream after this commit; ship it from its last pin.
GH_TUPLE=	iaolo:iA-Fonts:b337fe1a4c93026268f70e4b2678371f3e89e2ce:legacy

NO_ARCH=	yes
NO_BUILD=	yes

_FAMILIES=	Duo Mono Quattro
_STYLES=	Bold BoldItalic Italic Regular

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
.for f in ${_FAMILIES}
	${INSTALL_DATA} "${WRKSRC}/iA Writer ${f}/Static/"*.ttf \
		${STAGEDIR}${FONTSDIR}
.endfor
	${INSTALL_DATA} "${WRKSRC_legacy}/iA Writer Duospace/TTF (PC)/"*.ttf \
		${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
