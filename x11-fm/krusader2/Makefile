# New ports collection makefile for:	krusader
# Date created:		21-04-2003
# Whom:			Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	krusader
PORTVERSION=	1.30
PORTREVISION=	1
CATEGORIES=	x11-fm kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=krusader

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	A two window file-manager for KDE, like midnight or norton commander

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

QTDIR?=${X11BASE}/bin
KDEDIR?=${LOCALBASE}/bin
CONFIGURE_TARGET=
CONFIGURE_ENV+=QTDIR=${QTDIR} KDEDIR=${KDEDIR}
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

MAN1=	krusader.1

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "The following settings are assumed:"
	@${ECHO_MSG} "Installation directory of qt3: QTDIR=${QTDIR}"
	@${ECHO_MSG} "Installation directory of KDE3: KDEDIR=${KDEDIR}"
	@${ECHO_MSG} "If these assumptions are wrong, stop the build NOW and set the variables correpondingly!"
	@${ECHO_MSG}
	@sleep 3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
