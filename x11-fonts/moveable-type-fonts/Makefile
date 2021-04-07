PORTNAME=	moveable-type-fonts
PORTVERSION=	20100801
PORTREVISION=	2
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

NO_BUILD=	yes
USES=		fonts zip

post-extract:
	@${FIND} ${WRKDIR} -name __MACOSX | ${XARGS} ${RM} -r

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${FIND} ${WRKDIR} -name \*.ttf -exec ${INSTALL_DATA} {} ${STAGEDIR}${FONTSDIR} \;
	${FIND} ${WRKDIR} -name \*.otf -exec ${INSTALL_DATA} {} ${STAGEDIR}${FONTSDIR} \;

.include <bsd.port.mk>
