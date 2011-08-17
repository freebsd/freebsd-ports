# New ports collection makefile for:	ro-mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mythes
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/rospell/Romanian%20dictionaries/dict-${PORTVERSION}/
PKGNAMEPREFIX=	ro-
DISTNAME=	th_ro_RO.${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Romanian thesaurus

LICENSE=	GPLv2

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/th_ro_RO.dat \
		%%DATADIR%%/th_ro_RO.idx
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/th_ro_RO.dat ${WRKSRC}/th_ro_RO.idx ${DATADIR}/

.include <bsd.port.mk>
