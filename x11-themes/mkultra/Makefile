# New ports collection makefile for:	mkultra
# Date created:		August 16 2002
# Whom:			Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	mkultra
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	x11-wm kde
MASTER_SITES=	http://www.kde-look.org/content/files/
DISTNAME=	2865-${PORTNAME}-${PORTVERSION}

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	A lightweight native KWin style for KDE3

BROKEN=		'Does not build since KDE 3.2'
IGNORE=	${BROKEN}

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDEBASE_VER=3
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
