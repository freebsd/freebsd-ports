# New ports collection Makefile for:	libksba
# Date created:				July 17 2002
# Whom:					Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libksba
PORTVERSION=	0.4.6
CATEGORIES=	security
MASTER_SITES=	http://gd.tuwien.ac.at/privacy/gnupg/alpha/aegypten/ \
		ftp://ftp.gnupg.org/gcrypt/alpha/aegypten/ \
		http://ftp.hi.is/pub/mirrors/gnupg/alpha/aegypten/ \
		http://www.mirrors.wiretapped.net/security/cryptography/apps/pgp/GnuPG/alpha/aegypten/  \
		${MASTER_SITE_RINGSERVER}/net/gnupg/alpha/aegypten/ \

MAINTAINER=	arved@FreeBSD.org

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
GNU_CONFIGURE=	yes

pre-configure:
	@cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

.include <bsd.port.mk>
