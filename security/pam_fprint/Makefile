# Created by: barner
# $FreeBSD$

PORTNAME=	pam_fprint
PORTVERSION=	20080330
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/p/${PORTNAME:C/_/-/}
DISTNAME=	${PORTNAME:C/_/-/}_${PORTVERSION}+git.orig

MAINTAINER=	lichray@gmail.com
COMMENT=	PAM module offering finger print authentication using libfprint

LIB_DEPENDS=	fprint:${PORTSDIR}/security/libfprint

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

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
IGNORE=		dependency libfprint will not compile on FreeBsd < 8
.endif

pre-configure:
	cd ${WRKDIR} && ${ACLOCAL}

post-install:
	@${ECHO}
	@${ECHO} =========================================================================
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} =========================================================================
	@${ECHO}

.include <bsd.port.post.mk>
