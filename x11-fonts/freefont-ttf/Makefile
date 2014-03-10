# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	freefont-ttf
PORTVERSION=	20120503
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=freefont

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Free UCS Outline Fonts

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

LICENSE=	GPLv3

USES=		zip

WRKSRC=		${WRKDIR}/freefont-${PORTVERSION}
INSTALLDIR=	${STAGEDIR}${PREFIX}/lib/X11/fonts/${PORTNAME}
PORTDOCS=	AUTHORS ChangeLog CREDITS README

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && ${LOCALBASE}/bin/mkfontscale
	cd ${WRKSRC} && ${LOCALBASE}/bin/mkfontdir

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${INSTALLDIR}
	cd ${WRKSRC} && \
	${INSTALL_DATA} fonts.dir fonts.scale *.ttf ${INSTALLDIR}

.include <bsd.port.mk>
