# New ports collection makefile for:	kmenc15
# Date created:		Wed Dec 15 17:32:21 UTC 2004
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kmenc15
PORTVERSION=	0.02
CATEGORIES=	multimedia kde
MASTER_SITES=	http://dividedsky.net/~ods15/kmenc15/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	KDE advanced MEncoder frontend, ala, VirtualDub

BUILD_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mplayer \
		sox:${PORTSDIR}/audio/sox \
		yuvtoppm:${PORTSDIR}/graphics/netpbm

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/${PORTNAME}

post-patch:
# FreeBSD uses sed(1) -E -e instead of sed(1) -r
	@${REINPLACE_CMD} -E \
		-e 's|sed -r|${SED} -E -e|' \
		${BUILD_WRKSRC}/${MAKEFILE} \
		${WRKSRC}/dialog.cpp

do-configure:
# CXX{,FLAGS} safeness
# PTHREAD_{CFLAGS,LIBS} safeness
	@${REINPLACE_CMD} -E \
		-e 's|^(CPP[[:space:]]*=).*$$|\1${CXX}|' \
		-e 's|^(CFLAGS[[:space:]]*=).*$$|\1${CXXFLAGS} ${PTHREAD_CFLAGS}|' \
		-e 's|^(BFLAGS.*)$$|\1 ${PTHREAD_LIBS}|' \
		${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
