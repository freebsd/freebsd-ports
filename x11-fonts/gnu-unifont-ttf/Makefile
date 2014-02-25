# Created by: nrg milk <bsdports@gmail.com>
# $FreeBSD$

PORTNAME=	gnu-unifont-ttf
PORTVERSION=	20140214
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=unifont/unifont-6.3.${PORTVERSION}
DISTNAME=	unifont-6.3.${PORTVERSION}

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
	${INSTALL_DATA} ${WRKSRC}/unifont-6.3.${PORTVERSION}.ttf \
		${INSTALLDIR}/unifont.ttf
	${INSTALL_DATA} ${WRKSRC}/unifont_csur-6.3.${PORTVERSION}.ttf \
		${INSTALLDIR}/unifont_csur.ttf
	${INSTALL_DATA} ${WRKSRC}/unifont_upper-6.3.${PORTVERSION}.ttf \
		${INSTALLDIR}/unifont_upper.ttf
	${INSTALL_DATA} ${WRKSRC}/unifont_upper_csur-6.3.${PORTVERSION}.ttf \
		${INSTALLDIR}/unifont_upper_csur.ttf
	${LOCALBASE}/bin/mkfontscale ${INSTALLDIR}
	${LOCALBASE}/bin/mkfontdir ${INSTALLDIR}

.include <bsd.port.mk>
