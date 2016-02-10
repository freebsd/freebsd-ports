# Created by: SeaD
# $FreeBSD$

PORTNAME=	echat
DISTVERSION=	0.04beta1
CATEGORIES=	net-im
MASTER_SITES=	http://echat.deep.perm.ru/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LAN chat program over the TCP/IP networks

USES=		ncurses
MAKE_ARGS=	LIBS="${LDFLAGS} -lncurses"
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS+=|g ; \
		s|PREFIX=|PREFIX?=|g ; s|CC=|CC?=|g; \
		\|^CFLAGS| { s|-g||; s|-O2||; } ; \
		\|CC|s|@||; \|install|s|-s|${STRIP}|; \
		s|PREFIX)|DESTDIR)$$(&|' ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/.echatrc.sample \
		${STAGEDIR}${PREFIX}/etc/echatrc.sample

.include <bsd.port.mk>
