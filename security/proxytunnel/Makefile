# New ports collection makefile for:		proxytunnel
# Date created:					Sun Nov 25 15:16:44 BRST 2001
# Whom:						Hammurabi Mendes <hmendes@brturbo.com>
#
# $FreeBSD$
#

PORTNAME=	proxytunnel
PORTVERSION=	1.9.0
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20source%20tarballs/${PORTNAME}%20${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Connects stdin and stdout to an origin server through an HTTPS proxy

USE_GMAKE=	yes
USE_GNOME=	pkgconfig
MAKE_JOBS_SAFE=	yes

ALL_TARGET=	${PORTNAME}

MAN1=		proxytunnel.1
PLIST_FILES=	bin/proxytunnel

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
