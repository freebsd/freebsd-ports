# New ports collection makefile for:	pgpgpg
# Date created:				16 December 1999
# Whom:					Matt Behrens <matt@zigg.com>
#
# $FreeBSD$
#

PORTNAME=	pgpgpg
PORTVERSION=	0.13
CATEGORIES=	security
MASTER_SITES=	http://www.nessie.de/mroth/pgpgpg/ \
		ftp://ftp.gnupg.org/pub/gcrypt/pgpgpg/

MAINTAINER=	matt@zigg.com

# BUILD_DEPENDS is necessary because the configure script will bomb out
# if it can't find gpg.  RUN_DEPENDS is necessary to make the package
# dependency register correctly.  Hence the apparent redundancy.

BUILD_DEPENDS=	${PREFIX}/bin/gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	${PREFIX}/bin/gpg:${PORTSDIR}/security/gnupg

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gpg-path=${PREFIX}/bin/gpg

.include <bsd.port.mk>
