# New ports collection makefile for:  nast
# Date created:        Sun Apr  6 10:12:16 CEST 2003
# Whom:                Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	nast
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://nast.berlios.de/src/ \
		http://voodoo.oberon.net/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Nast is a packet sniffer

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet-devel

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet-config

MAN8=		nast.8

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"
USE_GMAKE=	yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/nast

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""#######################################################
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You need ${PORTSDIR}/net/libnet-devel to build this port
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""#######################################################
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS="-Wall -O2 -pthread"||g' \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MANPREFIX}/man/man8

post-install:
	${CHMOD} 0755 ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
