# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yoono
PORTVERSION=	1.8.42
#PORTREVISION=	0
CATEGORIES=	net-im
MASTER_SITES=	http://cdn.yoono.com/desktop/
DISTNAME=	${PORTNAME}-desktop-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Client for Twitter and other social networks

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

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	alsalib dbuslibs gtk2 xorglibs

WRKSRC=	${WRKDIR}/${PORTNAME}-desktop

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && \
	${COPYTREE_SHARE} . ${DATADIR}
	${CHMOD} ${BINMODE} ${DATADIR}/${PORTNAME}-desktop
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
