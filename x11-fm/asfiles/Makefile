# New ports collection makefile for:   ASFiles
# Version required:		1.0
# Date created:                17 August 1997
# Whom:                        lukin@okbmei.msk.su
#
# $Id: Makefile,v 1.8 1999/01/18 06:43:03 asami Exp $
#

DISTNAME=	ASFiles-1.0
PKGNAME=	asfiles-1.0
CATEGORIES=	x11-fm windowmaker
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/X/afterstep/apps/ASFiles/ \
		ftp://ftp.uni-trier.de/pub/unix/X11/window-manager/AfterStep/apps/ASFiles/

MAINTAINER=	lukin@okbmei.msk.su

LIB_DEPENDS=	Dnd.1:${PORTSDIR}/x11/libdnd \
		Xpm.4:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
MAN1=	files.1
MAN3=	regexp.3

.include <bsd.port.mk>
