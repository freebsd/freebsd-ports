# New ports collection makefile for:	krusader
# Date created:		21-04-2003
# Whom:			Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	krusader
PORTVERSION=	1.90.0
PORTREVISION=	2
CATEGORIES=	x11-fm kde
MASTER_SITES=	SF

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	A two window file-manager for KDE, like midnight or norton commander

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_GETTEXT=	yes

QTDIR?=${QT_PREFIX}/bin
KDEDIR?=${LOCALBASE}/bin
CONFIGURE_ENV+=QTDIR=${QTDIR} KDEDIR=${KDEDIR}
LD_CONFIG=	yes
INSTALLS_ICONS=	yes

MAN1=	krusader.1

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "The following settings are assumed:"
	@${ECHO_MSG} "Installation directory of qt3: QTDIR=${QTDIR}"
	@${ECHO_MSG} "Installation directory of KDE3: KDEDIR=${KDEDIR}"
	@${ECHO_MSG} "If these assumptions are wrong, stop the build NOW and set the variables correspondingly!"
	@${ECHO_MSG}
	@sleep 3

pre-configure:
	${RM} ${WRKSRC}/admin/cvs.sh
	${TOUCH} ${WRKSRC}/admin/cvs.sh

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
