# New ports collection makefile for:    echat
# Date created:        26 Aug 2003
# Whom:                SeaD
#
# $FreeBSD$
#

PORTNAME=	echat
PORTVERSION=	0.02f2
CATEGORIES=	net
MASTER_SITES=	http://echat.deep.perm.ru/files/

MAINTAINER=	sead@mail.ru
COMMENT=	LAN chat program over the TCP/IP networks

USE_REINPLACE=	yes

MAN1=		echat.1

post-patch:
	${REINPLACE_CMD} -e \
	's|^CFLAGS=|CFLAGS+=|g ; \
	s|PREFIX=/usr/local|PREFIX=${PREFIX}|g ; \
	s|CC=|CC?=|g' \
		${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/.echatrc.sample ${PREFIX}/etc/echatrc.sample
	@${ECHO} "======================================================================"
	@${ECHO} "  Please put \"${PREFIX}/etc/echatrc.sample\" in the right place."
	@${ECHO} "  eChat will search in \"~/.echatrc\". Then edit it as you want."
	@${ECHO} "======================================================================"

.include <bsd.port.mk>
