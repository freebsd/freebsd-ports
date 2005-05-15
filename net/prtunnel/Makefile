# New ports collection makefile for:	prtunnel
# Date created:		19.06.2003
# Whom:			Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	prtunnel
PORTVERSION=	0.2.5
CATEGORIES=	net
MASTER_SITES=	http://joshbeam.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tunnel for TCP connections using an HTTP or SOCKS5 proxy

USE_REINPLACE=	yes
ALL_TARGET=	${PORTNAME}

MAN1=		prtunnel.1

PORTDOCS=	README
PLIST_FILES=	bin/prtunnel

post-patch:
	@${REINPLACE_CMD} -e 's|^PREFIX=|#PREFIX=|g ; \
	s|CC=gcc|CC?=gcc|g ; \
	s|CFLAGS=|CFLAGS+=|g' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
