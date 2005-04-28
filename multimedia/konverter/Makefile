# New ports collection makefile for:	konverter
# Date created:		Wed Dec 15 16:49:57 UTC 2004
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	konverter
DISTVERSION=	0.92-beta1
PORTREVISION=	3
CATEGORIES=	multimedia kde
MASTER_SITES=	http://www.kraus.tk/projects/konverter/sources/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	KDE MEncoder frontend

BUILD_DEPENDS=	avimerge:${PORTSDIR}/multimedia/transcode \
		mencoder:${PORTSDIR}/multimedia/mplayer
LIB_DEPENDS=	xine.13:${PORTSDIR}/multimedia/libxine

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure
#EXTRA_PATCHES=	${PORTSDIR}/x11/kde3/files/extrapatch-old_configure

post-patch:
# spelling fix
# Concatination -> Concatenation
	@${REINPLACE_CMD} -E \
		-e 's|Concatination|Concatenation|' \
		${WRKSRC}/src/KonverterMainDialog.ui

.include <bsd.port.mk>
