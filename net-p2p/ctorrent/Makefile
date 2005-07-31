# New ports collection makefile for:	ctorrent
# Date created:				Jan 17 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	ctorrent
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	BitTorrent Client written in C for FreeBSD and Linux

GNU_CONFIGURE=	yes
USE_BZIP2=	yes

PATCH_SITES=	http://www.rahul.net/dholmes/ctorrent/
PATCHFILES=	patchset-ctorrent-1.3.4-dnh1.diff

PLIST_FILES=	bin/ctorrent
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

PORTDOCS=	README-DNH.TXT

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
