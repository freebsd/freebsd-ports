PORTNAME=	selawik
DISTVERSION=	1.01
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/microsoft/Selawik/releases/download/${DISTVERSION}/:fonts \
		https://raw.githubusercontent.com/microsoft/Selawik/master/:license
DISTFILES=	Selawik_Release.zip:fonts \
		LICENSE.txt:license
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	Selawik_Release.zip

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Selawik is an open source replacement for Segoe UI
WWW=		https://github.com/microsoft/Selawik

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE.txt

USES=		fonts zip
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/selawk.ttf \
		${FONTSDIR}/selawkb.ttf \
		${FONTSDIR}/selawkl.ttf \
		${FONTSDIR}/selawksb.ttf \
		${FONTSDIR}/selawksl.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKDIR}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
