# $FreeBSD$

PORTNAME=	pam_kde
PORTVERSION=	1.0
CATEGORIES=	security kde
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PAM modules for KDE Display Manager

NO_BUILD=	yes

PLIST_FILES=	etc/pam.d/kde

OPTIONS_DEFINE=	AUTOLOGIN
OPTIONS_DEFAULT=	AUTOLOGIN
AUTOLOGIN_DESC=	Install module for automatic login

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAUTOLOGIN}
PLIST_FILES+=	etc/pam.d/kde-np
.endif

do-install:
	${INSTALL_DATA} ${FILESDIR}/kde ${PREFIX}/etc/pam.d
.if ${PORT_OPTIONS:MAUTOLOGIN}
	${INSTALL_DATA} ${FILESDIR}/kde-np ${PREFIX}/etc/pam.d
.endif

.include <bsd.port.mk>
