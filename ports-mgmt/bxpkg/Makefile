# New ports collection makefile for:	bxpkg
# Date Created:				7 February 2011
# Whom:				 	Kostas Petrikas <kpetrikas@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bxpkg
DISTVERSION=	0.0.3_0
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://hg.bsdroot.lv/expl/bxpkg/archive/
DISTNAME=	${DISTVERSION}

MAINTAINER=	kpetrikas@gmail.com
COMMENT=	bxPKG is a GTK+ based tool to manage binary packages on BSD systems.

USE_XORG=	x11
USE_GNOME=	gtk20

PLIST_FILES=	bin/bxpkg
USE_BZIP2=	YES

WRKSRC=	${WRKDIR}/${PORTNAME}-${DISTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
LIB_DEPENDS+=	archive.10:${PORTSDIR}/archivers/libarchive
.endif

.include <bsd.port.post.mk>
