# New ports collection makefile for:  		packit
# Date created:        				02.06.2003
# Whom:               				Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	packit
PORTVERSION=	0.7.1
CATEGORIES=	net
MASTER_SITES=	http://packit.sourceforge.net/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Network auditing tool

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet-devel

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet-config
MAN8=		packit.8
PLIST_FILES=	sbin/packit

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.if defined(WITHOUT_CAPTURE)
CONFIGURE_ARGS+=	--without-capture
.endif
.if defined(WITHOUT_INJECTION)
CONFIGURE_ARGS+=	--without-injection
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""#######################################################
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You need ${PORTSDIR}/net/libnet-devel to build this port
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""#######################################################
	@${ECHO_MSG} ""

.include <bsd.port.mk>
