# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	packit
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://packit.sourceforge.net/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network auditing tool

LIB_DEPENDS=	libnet.so:net/libnet

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PLIST_FILES=	sbin/packit \
		man/man8/packit.8.gz

.if defined(WITHOUT_CAPTURE)
CONFIGURE_ARGS+=	--without-capture
.endif
.if defined(WITHOUT_INJECTION)
CONFIGURE_ARGS+=	--without-injection
.endif

.include <bsd.port.mk>
