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

MAINTAINER=	flynn@energyhq.homeip.net
COMMENT=	A lightweight native KWin style for KDE3

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake \
		autoconf:${PORTSDIR}/devel/autoconf

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDEBASE_VER=3
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
