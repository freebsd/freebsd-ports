# New ports collection makefile for:	hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	it-hunspell
PORTVERSION=	2.4.2007.09.01
CATEGORIES=	textproc
MASTER_SITES=	SF/linguistico/Dizionario%20italiano%20per%20OOo/${PORTVERSION:S/./_/g}/
DISTNAME=	italiano_${PORTVERSION:S/./_/g}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Hunspell italian dictionnary

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/it_IT.aff \
		share/hunspell/it_IT.dic
PLIST_DIRS=	share/hunspell

do-install:
		@${MKDIR} ${PREFIX}/share/hunspell
		@${INSTALL_DATA} ${WRKDIR}/it_IT.aff \
			${WRKDIR}/it_IT.dic \
			${PREFIX}/share/hunspell/

.include <bsd.port.mk>
