# New ports collection makefile for:	thefish
# Date created:			Sat Mar 16 17:49:09 CET 2002
# Whom:				Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	thefish
PORTVERSION=	0.2.4
CATEGORIES=	sysutils
MASTER_SITES=	http://energyhq.homeip.net/files/

MAINTAINER=	flynn@energyhq.homeip.net

.if !defined(NO_GUI) && !defined(WITH_GTK12)
LIB_DEPENDS=	gtk-x11-2.0:${PORTSDIR}/x11-toolkits/gtk20
.endif
.if !defined(NO_GUI)
USE_X_PREFIX=	yes
.endif
.if !defined(NO_GUI) && defined(WITH_GTK12)
USE_GNOMENG=	yes
USE_GNOME=	gtk12
PKGNAMESUFFIX=	-gtk
.endif

MAN1=		thefish.1

pre-everything::
	@${CAT} ${PKGMESSAGE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/thefish ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/thefish.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
