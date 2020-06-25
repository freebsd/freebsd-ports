# Created by: Florent Thoumie <flz@xbsd.org>
# $FreeBSD$

PORTNAME=	ctorrent
PORTVERSION=	3.3.2
PORTREVISION=	4
CATEGORIES=	net-p2p
MASTER_SITES=	SF/dtorrent/dtorrent/${PORTVERSION} \
		http://www.rahul.net/dholmes/ctorrent/
DISTNAME=	${PORTNAME}-dnh${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	BitTorrent Client written in C for FreeBSD and Linux

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	ssl

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ctorrent
PORTDOCS=	README-DNH.TXT UserGuide

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
