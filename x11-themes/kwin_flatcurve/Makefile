# New ports collection makefile for:    kwin_flatcurve
# Date created:        30 January 2003
# Whom:                R. Joseph Wright <rjoseph@arbornet.org>
#
# $FreeBSD$

PORTNAME=	kwin_flatcurve
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	http://kde-look.org/content/files/
DISTNAME=	4365-flatcurve-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bluecurve style window decoration for KDEs WM

BROKEN=		"Does not build with KDE 3.2"
EXPIRATION_DATE=2005-02-18
DEPRECATED=	${BROKEN}

USE_KDEBASE_VER=	3
WRKSRC=		${WRKDIR}/flatcurve-${PORTVERSION}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
