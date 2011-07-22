# New ports collection makefile for:	wa-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wa-hunspell
PORTVERSION=	0.4.15
CATEGORIES=	textproc
MASTER_SITES=	http://chanae.walon.org/walon/
DISTNAME=	aspell-wa-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Wallon hunspell dictionaries

BUILD_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell

ALL_TARGET=	myspell

USE_BZIP2=	yes
WRKSRC=	${WRKDIR}/${DISTNAME}

PLIST_FILES=	share/hunspell/wa.aff \
		share/hunspell/wa.dic

PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKSRC}/wa.aff ${WRKSRC}/wa.dic ${PREFIX}/share/hunspell

.include <bsd.port.mk>
