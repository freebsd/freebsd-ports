# $FreeBSD$

PORTNAME=	pam_kde
PORTVERSION=	1.0
CATEGORIES=	security kde
DISTFILES=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PAM modules for KDE Display Manager

NO_BUILD=	yes

PLIST_FILES=	etc/pam.d/kde

OPTIONS_DEFINE=	AUTOLOGIN
OPTIONS_DEFAULT=	AUTOLOGIN
AUTOLOGIN_DESC=	Install module for automatic login
AUTOLOGIN_PLIST_FILES=	etc/pam.d/kde-np

do-install:
	${INSTALL_DATA} ${PLIST_FILES:S,etc/pam.d,${FILESDIR},} ${STAGEDIR}${PREFIX}/etc/pam.d

.include <bsd.port.mk>
