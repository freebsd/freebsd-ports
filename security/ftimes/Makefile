# New ports collection makefile for:   ftimes
# Date created:                20 August 2002
# Whom:                        Klayton Monroe <klm@ir.exodus.net>
#
# $FreeBSD$
#

PORTNAME=		ftimes
PORTVERSION=		3.2.1
PORTREVISION=		1
CATEGORIES=		security sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ftimes
EXTRACT_SUFX=		.tgz

MAINTAINER=		klm@ir.exodus.net
COMMENT=		A system baselining and evidence collection tool

GNU_CONFIGURE=		YES

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS=		--without-ssl
.else
USE_OPENSSL=		YES
CONFIGURE_ARGS=		--with-ssl=${OPENSSLBASE}
.endif

MAN1=			ftimes.1

post-install:
	strip ${PREFIX}/bin/ftimes

.include <bsd.port.mk>
