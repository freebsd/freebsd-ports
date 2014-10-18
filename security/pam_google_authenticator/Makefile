# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	pam_google_authenticator
PORTVERSION=	20140826
CATEGORIES=	security
MASTER_SITES=	LOCAL/riggs/google-authenticator
DISTNAME=	google-authenticator-${PORTVERSION}

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	PAM module for two-step authentication from Google

LICENSE=	APACHE20

USES=		gmake

PLIST_FILES=	bin/google-authenticator lib/pam_google_authenticator.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/google-authenticator \
		${STAGEDIR}${PREFIX}/bin/google-authenticator
	${INSTALL_LIB} ${WRKSRC}/pam_google_authenticator.so \
		${STAGEDIR}${PREFIX}/lib/pam_google_authenticator.so

.include <bsd.port.mk>
