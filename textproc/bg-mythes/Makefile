# New ports collection makefile for:	bg-mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mythes
PORTVERSION=	4.3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/bgoffice/OpenOffice.org%20Thesaurus%20BG/${PORTVERSION}/
PKGNAMEPREFIX=	bg-
DISTNAME=	OOo-thes-bg-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Bulgarian thesaurus

LICENSE=	GPLv2 LGPL21 MPL
LICENSE_COMB=	dual

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/th_bg_BG.dat \
		%%DATADIR%%/th_bg_BG.idx
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/th_bg_BG.dat ${WRKSRC}/th_bg_BG.idx ${DATADIR}/

.include <bsd.port.mk>
