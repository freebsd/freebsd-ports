# New ports collection makefile for:	4g8
# Date created:				25.01.2004
# Whom:					krion
#
# $FreeBSD$
#

PORTNAME=	4g8
PORTVERSION=	0.9b
CATEGORIES=	net
MASTER_SITES=	http://forgate.sourceforge.net/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	krion@FreeBSD.org
COMMENT=	4g8 is a tool that allows you to capture traffic

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet-devel

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

PLIST_FILES=	sbin/4g8

.include <bsd.port.mk>
