# Created by: Jui-Nan Lin <jnlin@freebsd.cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	pam_google_authenticator
PORTVERSION=	1.01.20160208
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security

MAINTAINER=	jnlin@freebsd.cs.nctu.edu.tw
COMMENT=	PAM module for two-step authentication from Google

LICENSE=	APACHE20

USES=		autoreconf gmake libtool
GNU_CONFIGURE=	YES

WRKSRC_SUBDIR=	libpam

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	google-authenticator
GH_TAGNAME=	195ddc1

post-patch:
	@${REINPLACE_CMD} -e 's;/security;;'	\
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
