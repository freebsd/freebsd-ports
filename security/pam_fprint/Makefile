# New ports collection makefile for:	pam_fprint
# Date created:				April 12 2008
# Whom:					barner
#
# $FreeBSD$
#

PORTNAME=	pam_fprint
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/fprint/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PAM module offering finger print authentication using libfprint

LIB_DEPENDS=	fprint:${PORTSDIR}/security/libfprint

CONFIGURE_ENV+=	FPRINT_CFLAGS=-I${LOCALBASE}/include
GNU_CONFIGURE=	yes

USE_BZIP2=	yes
USE_GNOME=	pkgconfig

PLIST_FILES+=	bin/pam_fprint_enroll \
		lib/pam_fprint.so

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

post-install:
	@${ECHO}
	@${ECHO} =========================================================================
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} =========================================================================
	@${ECHO}

.include <bsd.port.mk>
