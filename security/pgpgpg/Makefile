# New ports collection makefile for:	pgpgpg
# Date created:				16 December 1999
# Whom:					Matt Behrens <matt@zigg.com>
#
# $FreeBSD$
#

PORTNAME=	pgpgpg
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG} \
		http://www.nessie.de/mroth/%SUBDIR%/
MASTER_SITE_SUBDIR=	pgpgpg

MAINTAINER=	matt@zigg.com
COMMENT=	Wrapper for GnuPG to simulate PGP 2.6.x

# BUILD_DEPENDS is necessary because the configure script will bomb out
# if it can't find gpg.  RUN_DEPENDS is necessary to make the package
# dependency register correctly.  Hence the apparent redundancy.

BUILD_DEPENDS=	${PREFIX}/bin/gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	${PREFIX}/bin/gpg:${PORTSDIR}/security/gnupg

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gpg-path=${PREFIX}/bin/gpg
PLIST_FILES=	bin/pgpgpg

.include <bsd.port.mk>
