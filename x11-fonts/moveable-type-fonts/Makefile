# $FreeBSD$

PORTNAME=	moveable-type-fonts
PORTVERSION=	20100801
CATEGORIES=	x11-fonts
MASTER_SITES=	http://s3.amazonaws.com/theleague-production/fonts/
DISTFILES=	junction.zip \
		orbitron.zip \
		prociono.zip \
		raleway.zip \
		sniglet.zip \
		chunk.zip \
		blackout.zip \
		sorts-mill-goudy.zip \
		league-gothic.zip \
		goudy-bookletter-1911.zip

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Collection of open source fonts

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

NO_BUILD=	yes
USES=		zip

FONTDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

post-extract:
	@${FIND} ${WRKDIR} -name __MACOSX | ${XARGS} ${RM} -r

do-install:
	@${MKDIR} ${STAGEDIR}${FONTDIR}
	${FIND} ${WRKDIR} -name \*.ttf -exec ${INSTALL_DATA} {} ${STAGEDIR}${FONTDIR} \;
	${FIND} ${WRKDIR} -name \*.otf -exec ${INSTALL_DATA} {} ${STAGEDIR}${FONTDIR} \;

.include <bsd.port.mk>
