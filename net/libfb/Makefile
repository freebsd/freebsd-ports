# New ports collection makefile for:	libfb
# Date created:				12 Jan 2010
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libfb
PORTVERSION=	2.0.0
CATEGORIES=	net-mgmt
MASTER_SITES=	http://support.red-fone.com/downloads/fonulator/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	A foneBRIDGE configuration library

GNU_CONFIGURE=	yes
CONFIGURE_ENV=\
	CPPFLAGS="${LIBNET_CPPFLAGS}"\
	LDFLAGS="${LIBNET_LIBS:N-l*}"
CONFIGURE_ARGS=	--disable-shared

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet
LIBNET_CONFIG=	${LOCALBASE}/bin/libnet11-config

.if 0
# this does not work when LIBNET_CONFIG does not exist prior to building this port
LIBNET_CPPFLAGS!=	${LIBNET_CONFIG} --cflags --defines
LIBNET_LIBS!=		${LIBNET_CONFIG} --libs
.else
LIBNET_CPPFLAGS=	-I${LOCALBASE}/include/libnet11
LIBNET_LIBS=		-L${LOCALBASE}/lib/libnet11
.endif

.include <bsd.port.mk>
