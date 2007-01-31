# New ports collection makefile for:  		packit
# Date created:        				02.06.2003
# Whom:               				Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	packit
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://packit.sourceforge.net/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network auditing tool

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="`${LIBNET_CONFIG} --defines` `${LIBNET_CONFIG} --cflags`"

MAN8=		packit.8
PLIST_FILES=	sbin/packit

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

.if defined(WITHOUT_CAPTURE)
CONFIGURE_ARGS+=	--without-capture
.endif
.if defined(WITHOUT_INJECTION)
CONFIGURE_ARGS+=	--without-injection
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
