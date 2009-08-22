# New ports collection makefile for:	fprint_demo
# Date created:				April 12 2008
# Whom:					barner
#
# $FreeBSD$
#

PORTNAME=	fprint_demo
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/fprint/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Demo and test application for libfprint

LIB_DEPENDS=	fprint:${PORTSDIR}/security/libfprint

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	atk glib20 gtk20 pango pkgconfig

PLIST_FILES+=	bin/fprint_demo

.include <bsd.port.pre.mk>

CONFIGURE_ENV+=	CRYPTO_CFLAGS=-I${OPENSSLINC} \
		CRYPTO_LIBS=-lcrypto \
		CFLAGS="${CFLAGS} -DHAVE_MEMMEM"

post-install:
	@${ECHO}
	@${ECHO} =========================================================================
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} =========================================================================
	@${ECHO}

.include <bsd.port.post.mk>
