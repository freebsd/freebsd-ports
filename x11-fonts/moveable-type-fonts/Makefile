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
COMMENT=	A collection of open source fonts

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

NO_BUILD=	yes
USES=		zip
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"

NO_STAGE=	yes
post-extract:
	@${FIND} ${WRKDIR} -name __MACOSX | ${XARGS} ${RM} -r

do-install:
	@${MKDIR} ${FONTSDIR}
	@${FIND} ${WRKDIR} -name \*.ttf -exec ${INSTALL_DATA} {} ${FONTSDIR} \;
	@${FIND} ${WRKDIR} -name \*.otf -exec ${INSTALL_DATA} {} ${FONTSDIR} \;

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}

.include <bsd.port.mk>
