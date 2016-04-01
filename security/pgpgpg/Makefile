# Created by: Matt Behrens <matt@zigg.com>
# $FreeBSD$

PORTNAME=	pgpgpg
PORTVERSION=	0.13
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	PACKETSTORM/crypt/pgpgpg \
		ftp://ftp.gnupg.org/gcrypt/historic/ \
		http://www.nessie.de/mroth/pgpgpg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper for GnuPG to simulate PGP 2.6.x

# BUILD_DEPENDS is necessary because the configure script will bomb out
# if it can't find gpg.  RUN_DEPENDS is necessary to make the package
# dependency register correctly.  Hence the apparent redundancy.

BUILD_DEPENDS=	${PREFIX}/bin/gpgv:security/gnupg1
RUN_DEPENDS=	${PREFIX}/bin/gpgv:security/gnupg1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gpg-path=${PREFIX}/bin/gpg
PLIST_FILES=	bin/pgpgpg

.include <bsd.port.mk>
