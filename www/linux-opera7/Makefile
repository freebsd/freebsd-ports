# New ports collection makefile for:		linux-opera4
# Date created:					December 6th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	6.03.20020813
CATEGORIES=	www linux
MASTER_SITES=	http://opera.online.no/linux/603/final/en/qt_static/ \
		ftp://ftp.opera.com/pub/opera/linux/603/final/en/qt_static/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/03./03-/}.1-static-qt.i386

MAINTAINER=	des@FreeBSD.org

RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libXm.so.2:${PORTSDIR}/x11-toolkits/linux-openmotif \
		${LINUXBASE}/usr/lib/libpng.so.2:${PORTSDIR}/graphics/linux-png

USE_BZIP2=	yes
USE_LINUX=	yes
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
NO_FILTER_SHLIBS=yes

do-configure:
	${REINPLACE_CMD} -e \
	    's|%%PREFIX%%|${PREFIX}|g; s|%%DATADIR%%|${DATADIR}|g'\
	    ${WRKSRC}/install.sh

do-install:
	(cd ${WRKSRC} && ./install.sh \
	    --exec_prefix=${DATADIR}/bin \
	    --wrapperdir=${PREFIX}/bin \
	    --docdir=${DOCSDIR} \
	    --sharedir=${DATADIR} \
	    --plugindir=${DATADIR}/plugins )

.include <bsd.port.mk>
