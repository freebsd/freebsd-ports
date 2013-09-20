# Created by: SeaD
# $FreeBSD$

PORTNAME=	echat
DISTVERSION=	0.04beta1
CATEGORIES=	net-im
MASTER_SITES=	http://echat.deep.perm.ru/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LAN chat program over the TCP/IP networks

MAN1=		echat.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS+=|g ; \
		s|PREFIX=|PREFIX?=|g ; s|CC=|CC?=|g; \
		\|^CFLAGS| { s|-g||; s|-O2||; } ; \
		\|CC|s|@||; \|install|s|-s|${STRIP}|' ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/.echatrc.sample ${PREFIX}/etc/echatrc.sample
	@${ECHO} "======================================================================"
	@${ECHO} "  Please put \"${PREFIX}/etc/echatrc.sample\" in the right place."
	@${ECHO} "  eChat will search in \"~/.echatrc\". Then edit it as you want."
	@${ECHO} "======================================================================"

.include <bsd.port.mk>
