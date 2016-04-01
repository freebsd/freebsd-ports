# Created by: barner
# $FreeBSD$

PORTNAME=	pam_fprint
PORTVERSION=	20080330
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	DEBIAN/pool/main/p/${PORTNAME:C/_/-/}
DISTNAME=	${PORTNAME:C/_/-/}_${PORTVERSION}+git.orig

MAINTAINER=	lichray@gmail.com
COMMENT=	PAM module offering finger print authentication using libfprint

LIB_DEPENDS=	libfprint.so:security/libfprint

USE_AUTOTOOLS=	autoconf automake
AUTOMAKE_ARGS=	-a
CONFIGURE_ENV+=	FPRINT_CFLAGS=-I${LOCALBASE}/include
GNU_CONFIGURE=	yes

USES=		pkgconfig

WRKSRC=	${WRKDIR}

PLIST_FILES+=	bin/pam_fprint_enroll \
		lib/pam_fprint.so

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

pre-configure:
	cd ${WRKDIR} && ${ACLOCAL}

.include <bsd.port.mk>
