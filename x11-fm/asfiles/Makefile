# New ports collection makefile for:   ASFiles
# Version required:		1.0
# Date created:                17 August 1997
# Whom:                        lukin@okbmei.msk.su
#
# $Id: Makefile,v 1.3 1998/08/07 22:33:10 asami Exp $
#

DISTNAME=	ASFiles-1.0
PKGNAME=	asfiles-1.0
CATEGORIES=	x11-fm
MASTER_SITES=	http://w3.one.net/~roz/software/x11/windowmaker/

MAINTAINER=	lukin@okbmei.msk.su

BUILD_DEPENDS=	${PREFIX}/lib/libDnd.a:${PORTSDIR}/x11/libdnd
LIB_DEPENDS=    Xpm.5:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
MAN1=	files.1
MAN3=	regexp.3

.include <bsd.port.mk>
