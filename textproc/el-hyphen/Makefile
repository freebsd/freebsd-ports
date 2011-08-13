# New ports collection makefile for:	el-hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hyphen
PORTVERSION=	2005.10.17
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
PKGNAMEPREFIX=	el-
DISTNAME=	hyph_el_GR

MAINTAINER=	office@FreeBSD.org
COMMENT=	Greek hyphenation rules

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_el_CY.dic \
		%%DATADIR%%/hyph_el_GR.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_el_GR.dic ${DATADIR}/
	${LN} -s hyph_el_GR.dic ${DATADIR}/hyph_el_CY.dic

.include <bsd.port.mk>
