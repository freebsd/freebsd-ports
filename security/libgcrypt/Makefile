# New ports collection Makefile for:	libgcrypt
# Date created:				July 17 2002
# Whom:					Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libgcrypt
PORTVERSION=	1.1.11
CATEGORIES=	security
MASTER_SITES=	http://gd.tuwien.ac.at/privacy/gnupg/alpha/libgcrypt/ \
		ftp://ftp.gnupg.org/gcrypt/alpha/libgcrypt/ \
		http://ftp.hi.is/pub/mirrors/gnupg/alpha/libgcrypt/ \
		http://www.mirrors.wiretapped.net/security/cryptography/apps/pgp/GnuPG/alpha/libgcrypt/  \
		${MASTER_SITE_RINGSERVER}/net/gnupg/alpha/libgcrypt/ \

MAINTAINER=	arved@FreeBSD.org

USE_REINPLACE=	yes
USE_PERL5=	yes
USE_AUTOCONF_VER=	253
USE_LIBTOOL=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|" \
		${WRKSRC}/scripts/ltmain.sh

pre-configure:
	@${RM} -f ${WRKSRC}/doc/gcrypt.info*

.include <bsd.port.mk>
