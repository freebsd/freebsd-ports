# New ports collection makefile for:	ctorrent
# Date created:				Jan 17 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	ctorrent
PORTVERSION=	${PATCHLEVEL}
PATCHLEVEL=	2.2
RELVERSION=	1.3.4
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.rahul.net/dholmes/ctorrent/
DISTFILES=	${PORTNAME}-${RELVERSION}-dnh${PATCHLEVEL}.tar.gz

MAINTAINER=	flz@FreeBSD.org
COMMENT=	BitTorrent Client written in C for FreeBSD and Linux

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-dnh${PATCHLEVEL}

PLIST_FILES=	bin/ctorrent
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

PORTDOCS=	README-DNH.TXT

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
