# New ports collection makefile for:	vtun
# Date created:				05 Feb 2000
# Whom:					Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vtun
PORTVERSION=	2.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vtun

MAINTAINER=	kevlo@FreeBSD.org

LIB_DEPENDS=	lzo.1:${PORTSDIR}/archivers/lzo

MAN5=		vtund.conf.5
MAN8=		vtund.8
MANCOMPRESSED=	no

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--localstatedir=/var \
		--with-crypto-headers=${LOCALBASE}/include/openssl \
		--with-crypto-lib=${LOCALBASE}/lib \
		--with-lzo-headers=${LOCALBASE}/include \
		--with-lzo-lib=${LOCALBASE}/lib

ALL_TARGET= 	vtund

.include <bsd.port.mk>
