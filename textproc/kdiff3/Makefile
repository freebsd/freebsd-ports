# New ports collection makefile for:	kdiff3
# Date created:		2003/01/03
# Whom:			Heiner Eichmann <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	kdiff3
PORTVERSION=	0.9.92
PORTREVISION=	3
CATEGORIES=	textproc kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	A KDE3 graphical frontend for diff

USE_KDEBASE_VER=3
USE_AUTOTOOLS=	libtool:15
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	${PREFIX}/lib/kde3

CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"

MAN1=	kdiff3.1

.include <bsd.port.mk>
