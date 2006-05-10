# New ports collection makefile for:	kmenc15
# Date created:		Wed Dec 15 17:32:21 UTC 2004
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kmenc15
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=kmenc15

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE advanced MEncoder frontend, ala, VirtualDub

RUN_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mplayer

USE_BZIP2=	yes
USE_KDELIBS_VER=	3
USE_GMAKE=	yes
MAKE_ARGS=	QTDIR="${QT_PREFIX}" \
		KDEDIR="${KDE_PREFIX}" \
		CPP="${CXX}" \
		CFLAGS="${PTHREAD_LIBS}" \
		CXXFLAGS="${CXXFLAGS} ${PTHREAD_CFLAGS}" \
		VERSION="${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|--no-backup-if-mismatch||g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
