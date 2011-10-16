# New ports collection Makefile for:	pam_kde
# Date created:				29 September 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pam_kde
PORTVERSION=	1.0
CATEGORIES=	security kde
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PAM modules for KDE Display Manager

NO_BUILD=	yes

PLIST_FILES=	etc/pam.d/kde

OPTIONS=	AUTOLOGIN "Install module for automatic login" on

.include <bsd.port.options.mk>

.ifndef(WITHOUT_AUTOLOGIN)
PLIST_FILES+=	etc/pam.d/kde-np
.endif

do-install:
	${INSTALL_DATA} ${FILESDIR}/kde ${PREFIX}/etc/pam.d
.ifndef(WITHOUT_AUTOLOGIN)
	${INSTALL_DATA} ${FILESDIR}/kde-np ${PREFIX}/etc/pam.d
.endif

.include <bsd.port.mk>
