# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	pam_google_authenticator
PORTVERSION=	20120831
CATEGORIES=	security
MASTER_SITES=	LOCAL/dumbbell
DISTNAME=	google-authenticator-${PORTVERSION}

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	PAM module for two-step authentication from Google

LICENSE=	APACHE20

USE_GMAKE=	yes

PLIST_FILES=	bin/google-authenticator lib/pam_google_authenticator.so

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/google-authenticator ${PREFIX}/bin/google-authenticator
	${INSTALL_LIB} ${WRKSRC}/pam_google_authenticator.so ${PREFIX}/lib/pam_google_authenticator.so

.include <bsd.port.mk>
