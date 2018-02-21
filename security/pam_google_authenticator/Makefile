# Created by: Jui-Nan Lin <jnlin@freebsd.cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	pam_google_authenticator
PORTVERSION=	1.05
PORTEPOCH=	1
CATEGORIES=	security

MAINTAINER=	jnlin@freebsd.cs.nctu.edu.tw
COMMENT=	PAM module for two-step authentication from Google

LICENSE=	APACHE20

USES=		autoreconf gmake libtool
GNU_CONFIGURE=	YES

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	google-authenticator-libpam

OPTIONS_DEFINE=	QRENCODE
OPTIONS_DEFAULT=	QRENCODE
QRENCODE_DESC=	Allow creation of QR-codes

QRENCODE_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode

post-patch:
	@${REINPLACE_CMD} -e 's;/security;;'	\
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
