# New ports collection makefile for:		relview
# Date created:					October 24 2002
# Whom:						Michael Ebert <ebert@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	relview
PORTVERSION=	7.0.2
PORTREVISION=	2
CATEGORIES=	math linux
MASTER_SITES=	ftp://ftp.informatik.uni-kiel.de/pub/kiel/relview/RELVIEW_7.0/LINUX/
PKGNAMEPREFIX=	linux-
EXTRACT_SUFX=	.gz

MAINTAINER=	ebert@informatik.unibw-muenchen.de
COMMENT=	An interactive tool for manipulation of relations

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes

NO_WRKSUBDIR=	yes
EXTRACT_AFTER_ARGS=	> ${DISTNAME}

NO_BUILD=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

do-install:
	${BRANDELF} -t Linux ${WRKDIR}/${DISTNAME}
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME} ${PREFIX}/bin
	${LN} -fhs ${PREFIX}/bin/${DISTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
