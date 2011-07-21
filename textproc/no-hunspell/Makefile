# New ports collection makefile for:	no-hunspell
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	no-hunspell
PORTVERSION=	2.0.10
CATEGORIES=	textproc
MASTER_SITES=	https://alioth.debian.org/frs/download.php/2357/
DISTNAME=	no_NO-pack2-${PORTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Norwegian (Nynorsk and Bokmaal) hunspell dictionaries

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/nb_NO.aff \
		share/hunspell/nb_NO.dic \
		share/hunspell/nn_NO.aff \
		share/hunspell/nn_NO.dic
PLIST_DIRS=	share/hunspell

post-extract:
	@${EXTRACT_CMD} ${WRKDIR}/nb_NO.zip -d ${WRKSRC}
	@${EXTRACT_CMD} ${WRKDIR}/nn_NO.zip -d ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKSRC}/n?_NO.* ${PREFIX}/share/hunspell

.include <bsd.port.mk>
