# New ports collection makefile for:	mcrypt
# Date created:		Mon Jun 28 18:02:04 PDT 1999
# Whom:			nsayer@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	libmcrypt
PORTVERSION=	2.4.15
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.hellug.gr/pub/unix/mcrypt/libmcrypt/ \
		ftp://ftp.ntua.gr/pub/security/mcrypt/libmcrypt/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	ltdl.1:${PORTSDIR}/devel/libtool

RESTRICTED=	"yes - cryptography"

USE_LIBTOOL=	yes
LIBTOOLFLAGS=	# empty
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes
PLIST_SUB=	CONFIGURE_TARGET=${CONFIGURE_TARGET}

MAN3=		mcrypt.3

pre-build:
	$(LN) -sf ${LOCALBASE}/bin/libtool ${WRKSRC}/libtool

.include <bsd.port.mk>
