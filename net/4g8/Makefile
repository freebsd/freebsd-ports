# New ports collection makefile for:	forgate
# Date created:				25.01.2004
# Whom:					krion
#
# $FreeBSD$
#

PORTNAME=	forgate
PORTVERSION=	0.9b
CATEGORIES=	net
MASTER_SITES=	http://forgate.sourceforge.net/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Forgate is a tool that allows you to capture traffic

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet-devel

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

PLIST_FILES=	sbin/forgate

.include <bsd.port.mk>
