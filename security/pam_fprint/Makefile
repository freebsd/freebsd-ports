PORTNAME=	pam_fprint
DISTVERSION=	20080330
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	Clockwork6400@protonmail.com
COMMENT=	PAM module offering finger print authentication using libfprint
WWW=		https://github.com/Clockwork6400/pam-fprint

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfprint.so:security/libfprint

GNU_CONFIGURE=	yes
USES=		autoreconf pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	Clockwork6400

PLIST_FILES+=	bin/pam_fprint_enroll \
		lib/pam_fprint.so

SUB_FILES=	pkg-message

.include <bsd.port.mk>
