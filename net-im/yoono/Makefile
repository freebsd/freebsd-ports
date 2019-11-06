# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yoono
PORTVERSION=	1.8.43
PORTREVISION=	1
#PORTREVISION=	0
CATEGORIES=	net-im
MASTER_SITES=	http://cdn.yoono.com/desktop/
DISTNAME=	${PORTNAME}-desktop-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Client for Twitter and other social networks

BROKEN=		unfetchable

LICENSE_NAME=	ToU
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_TEXT=	http://www.yoono.com/terms.html

DESKTOP_ENTRIES=	"Yoono" \
			"Linux Client for social networks" \
			"${DATADIR}/chrome/branding/content/icon64.png" \
			"yoono" \
			"GTK;Network;" \
			""

NO_BUILD=	yes

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	binary distribution

SUB_FILES=	${PORTNAME} pkg-message
SUB_LIST=	LINUXBASE=${LINUXBASE}

USES=		linux tar:bzip2
USE_LDCONFIG=	yes
USE_LINUX=	alsalib dbuslibs gtk2 xorglibs

WRKSRC=	${WRKDIR}/${PORTNAME}-desktop

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/${PORTNAME}-desktop
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
