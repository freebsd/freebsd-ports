# New ports collection makefile for:   satellite
# Date created:        24 Feb 2001
# Whom:                Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=       satellite
PORTVERSION=    1.0.2
CATEGORIES=     net-mgmt
MASTER_SITES=   ${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= system/network

MAINTAINER=	markp@FreeBSD.org
COMMENT=	A system for tracking machines with dynamic IP addresses

LIB_DEPENDS=    gdbm.3:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=  yes
CONFIGURE_ENV=  CPPFLAGS='-I${LOCALBASE}/include' \
		LDFLAGS='-L${LOCALBASE}/lib'
CONFIGURE_ARGS+=	--localstatedir=/var/log

MAN8=           satcfg.8 satellite.8 satellited.8 satwatch.8

pre-install:
	@${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
