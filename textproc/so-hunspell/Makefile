# New ports collection makefile for:	so-hunspell
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	so-hunspell
PORTVERSION=	1.0.2
CATEGORIES=	textproc
MASTER_SITES=	 ${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/13375
DISTNAME=	qaamuuska_af_soomaaliga-${PORTVERSION}-tb+fx
EXTRACT_SUFX=	.xpi

MAINTAINER=	office@FreeBSD.org
COMMENT=	Somali hunspell dictionaries

LICENSE=	GPLv2

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/so_SO.aff \
		share/hunspell/so_SO.dic
PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/so_SO* ${PREFIX}/share/hunspell/

.include <bsd.port.mk>
