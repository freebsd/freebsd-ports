# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

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

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"

PLIST_FILES=	bin/nast man/man8/nast.8.gz

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|CFLAGS="-Wall -O2 -pthread"||g; \
		 s|libnet-config|${LIBNET_CONFIG}|; \
		 s|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.post.mk>
