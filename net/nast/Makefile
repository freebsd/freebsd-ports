# New ports collection makefile for:  nast
# Date created:        Sun Apr  6 10:12:16 CEST 2003
# Whom:                Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	nast
PORTVERSION=	0.2.0
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A packet sniffer

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	net:${PORTSDIR}/net/libnet

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"

MAN8=		nast.8
PLIST_FILES=	bin/nast

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|CFLAGS="-Wall -O2 -pthread"||g; \
		 s|libnet-config|${LIBNET_CONFIG}|; \
		 s|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MANPREFIX}/man/man8

.include <bsd.port.post.mk>
