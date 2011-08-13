# New ports collection makefile for:	sv-hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hyphen
PORTVERSION=	2005.04.15
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
PKGNAMEPREFIX=	sv-
DISTNAME=	hyph_sv_SE

MAINTAINER=	office@FreeBSD.org
COMMENT=	Swedish hyphenation rules

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_sv_FI.dic \
		%%DATADIR%%/hyph_sv_SE.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_sv_SE.dic ${DATADIR}/
	${LN} -s hyph_sv_SE.dic ${DATADIR}/hyph_sv_FI.dic

.include <bsd.port.mk>
