# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	pam_google_authenticator
PORTVERSION=	20140826
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	LOCAL/riggs/google-authenticator
DISTNAME=	google-authenticator-${PORTVERSION}

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	PAM module for two-step authentication from Google

LICENSE=	APACHE20

OPTIONS_DEFINE=	STEPSIZE
STEPSIZE_DESC=	Allow time steps other than the default of 30 seconds
STEPSIZE_CFLAGS= -DSTEPSIZE

USES=		gmake

PLIST_FILES=	bin/google-authenticator lib/pam_google_authenticator.so

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/google-authenticator \
		${STAGEDIR}${PREFIX}/bin/google-authenticator
	${INSTALL_LIB} ${WRKSRC}/pam_google_authenticator.so \
		${STAGEDIR}${PREFIX}/lib/pam_google_authenticator.so

.include <bsd.port.mk>
