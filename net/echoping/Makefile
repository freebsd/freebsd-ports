# New ports collection makefile for:	echoping
# Date created:		13 April 1997
# Whom:			peter
#
# $FreeBSD$
#

PORTNAME=	echoping
PORTVERSION=	5.2.0
CATEGORIES=	net ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=		${PORTNAME}

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	A ping-like program that uses tcp and/or http

LIB_DEPENDS=	idn.13:${PORTSDIR}/devel/libidn

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-http --enable-icp --enable-smtp --with-ssl \
		--enable-ttcp --enable-tos --with-libidn=${LOCALBASE}

MAN1=		echoping.1
PLIST_FILES=	bin/echoping

.include <bsd.port.mk>
