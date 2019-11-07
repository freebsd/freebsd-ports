# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	datalegreya
PORTVERSION=	0.2017.03.29
PORTREVISION=	1
CATEGORIES=	x11-fonts math textproc

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Typeface that melts text and data visualisation

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/SIL\ Open\ Font\ License.txt

USE_GITHUB=	yes
GH_ACCOUNT=	figs-lab
GH_TAGNAME=	bb0872f

USES=		fonts xorg
USE_XORG=	x11
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	%%FONTSDIR%%/Datalegreya-Dot.otf	\
		%%FONTSDIR%%/Datalegreya-Gradient.otf	\
		%%FONTSDIR%%/Datalegreya-Thin.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC}/font-files && ${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
