PORTNAME=	pam_kde
PORTVERSION=	1.0
CATEGORIES=	security kde
DISTFILES=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PAM modules for KDE Display Manager

NO_BUILD=	yes

PAM_FILES=	etc/pam.d/kde

OPTIONS_DEFINE=	AUTOLOGIN
OPTIONS_DEFAULT=	AUTOLOGIN
AUTOLOGIN_DESC=	Install module for automatic login
AUTOLOGIN_VARS=	PAM_FILES+=etc/pam.d/kde-np

PLIST_FILES=	${PAM_FILES}

do-install:
	${INSTALL_DATA} ${PAM_FILES:S,etc/pam.d,${FILESDIR},} ${STAGEDIR}${PREFIX}/etc/pam.d

.include <bsd.port.mk>
