# New ports collection makefile for:   	softhsm
# Date created:        15 December 2009
# Whom:                Jaap Akkerhuis <jaap@NLnetLabs.nl
#
# $FreeBSD$
#

PORTNAME=	softhsm
PORTVERSION=	1.2.0
CATEGORIES=	security
MASTER_SITES=	http://www.opendnssec.org/files/source/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	A software implementation of a Hardware Security Module (HSM)

LIB_DEPENDS=	botan:${PORTSDIR}/security/botan
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3

GNU_CONFIGURE=	yes

USE_LDCONFIG=	yes

MAN1=		softhsm.1 softhsm-keyconv.1
MAN5=		softhsm.conf.5

PLIST_FILES=	bin/softhsm \
		bin/softhsm-keyconv \
		lib/libsofthsm.a \
		lib/libsofthsm.la \
		lib/libsofthsm.so \
		etc/softhsm.conf \
		etc/softhsm.conf.sample

.include <bsd.port.mk>
