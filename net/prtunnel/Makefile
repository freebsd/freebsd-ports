# New ports collection makefile for:	prtunnel
# Date created:		19.06.2003
# Whom:			Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	prtunnel
PORTVERSION=	0.2.7
CATEGORIES=	net
MASTER_SITES=	http://joshbeam.com/files/

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Tunnel for TCP connections using an HTTP or SOCKS5 proxy

ALL_TARGET=	${PORTNAME}

MAN1=		prtunnel.1

PORTDOCS=	ChangeLog README
PLIST_FILES=	bin/prtunnel

post-patch:
	@${REINPLACE_CMD} -E '/^(CC|CFLAGS|PREFIX)/d' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
