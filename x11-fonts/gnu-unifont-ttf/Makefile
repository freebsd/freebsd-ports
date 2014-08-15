# $FreeBSD$

PORTNAME=	gnu-unifont-ttf
PORTVERSION=	7.0.03
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=unifont/unifont-${PORTVERSION}
DISTNAME=	unifont-${PORTVERSION}

MAINTAINER=	bsdports@gmail.com
COMMENT=	Unicode TrueType Font

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

NO_BUILD=	yes
FONTSDIR=	lib/X11/fonts/unifont
INSTALLDIR=	${STAGEDIR}${PREFIX}/${FONTSDIR}
PLIST_SUB=	FONTSDIR="${FONTSDIR}"
WRKSRC_SUBDIR=	font/precompiled

do-install:
	@${MKDIR} ${INSTALLDIR}
	${INSTALL_DATA} ${WRKSRC}/unifont-${PORTVERSION}.ttf \
		${INSTALLDIR}/unifont.ttf
	${INSTALL_DATA} ${WRKSRC}/unifont_csur-${PORTVERSION}.ttf \
		${INSTALLDIR}/unifont_csur.ttf
	${INSTALL_DATA} ${WRKSRC}/unifont_upper-${PORTVERSION}.ttf \
		${INSTALLDIR}/unifont_upper.ttf
	${INSTALL_DATA} ${WRKSRC}/unifont_upper_csur-${PORTVERSION}.ttf \
		${INSTALLDIR}/unifont_upper_csur.ttf
	${LOCALBASE}/bin/mkfontscale ${INSTALLDIR}
	${LOCALBASE}/bin/mkfontdir ${INSTALLDIR}

.include <bsd.port.mk>
