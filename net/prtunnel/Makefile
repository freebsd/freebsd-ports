# New ports collection makefile for:	prtunnel
# Date created:		19.06.2003
# Whom:			Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	prtunnel
PORTVERSION=	0.1.8
CATEGORIES=	net
MASTER_SITES=	http://joshbeam.com/files/

MAINTAINER=	ponomarew@oberon.net
COMMENT=	Tunnel for TCP connections using an HTTP or SOCKS5 proxy

USE_REINPLACE=	yes
ALL_TARGET=	${PORTNAME}

MAN1=		prtunnel.1

post-patch:
	@${REINPLACE_CMD} -e \
	's|%%PREFIX%%|${PREFIX}|g ; \
	s|CC=gcc|CC?=gcc|g' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
