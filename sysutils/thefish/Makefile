# New ports collection makefile for:	thefish
# Date created:			Sat Mar 16 17:49:09 CET 2002
# Whom:				Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	thefish
PORTVERSION=	0.2.5.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://energyhq.homeip.net/files/

MAINTAINER=	flynn@energyhq.homeip.net

.if defined(WITHOUT_X11) || defined(NO_GUI)
NO_GUI=		yes
MAKE_ENV+=	NO_GUI=yes
.else
LIB_DEPENDS=	gtk-x11-2.0:${PORTSDIR}/x11-toolkits/gtk20
USE_X_PREFIX=	yes
.endif

MAN1=		thefish.1

pre-everything::
	@${CAT} ${PKGMESSAGE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/thefish ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/thefish.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
