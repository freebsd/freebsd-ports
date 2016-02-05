# Created by: Elias Mandouvalos <ocean@compulink.gr>
# $FreeBSD$

PORTNAME=	tn5250
PORTVERSION=	0.17.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	5250 Telnet protocol and Terminal

USES=		libtool ncurses
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-os-dir=no --with-ssl=${OPENSSLBASE}
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS =/s|linux||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|: install-data-local|:|g' ${WRKSRC}/freebsd/Makefile.in

.include <bsd.port.mk>
