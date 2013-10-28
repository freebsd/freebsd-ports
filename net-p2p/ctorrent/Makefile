# Created by: Florent Thoumie <flz@xbsd.org>
# $FreeBSD$

PORTNAME=	ctorrent
PORTVERSION=	3.3.2
PORTREVISION=	3
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.rahul.net/dholmes/ctorrent/
DISTNAME=	${PORTNAME}-dnh${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	BitTorrent Client written in C for FreeBSD and Linux

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ctorrent
PORTDOCS=	README-DNH.TXT UserGuide

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
