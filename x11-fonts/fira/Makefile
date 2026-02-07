PORTNAME=	fira
DISTVERSION=	4.301
PORTREVISION=	2
CATEGORIES=	x11-fonts

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	Sans-serif, monospaced, and code typeface for small screens
WWW=		https://bboxtype.com/typefaces/FiraSans/

LICENSE=	OFL11

USES=		fonts

EXTRACT_AFTER_ARGS=	--include ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/Fira_Code_3_2/Fonts/FiraCode_OTF_32/*.otf \
			--include ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/Fira_Mono_3_2/Fonts/FiraMono_OTF_32/*.otf \
			--include ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/Fira_Sans_4_3/Fonts/Fira_Sans_OTF_4301 \
			--strip-components 4 \
			--no-same-owner --no-same-permissions

USE_GITHUB=	yes
GH_ACCOUNT=	bBoxType
GH_PROJECT=	FiraSans
GH_TAGNAME=	f54eeb3

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.otf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*/*/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
