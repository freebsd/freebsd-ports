# New ports collection makefile for:	hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hyphen
PORTVERSION=	2004.04.15
PORTREVISION=	1
CATEGORIES=	portuguese textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
DISTNAME=	hyph_pt_PT-${PORTVERSION:C/\.//g}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Portuguese hyphenation rules

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_pt_BR.dic \
		%%DATADIR%%/hyph_pt_PT.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_pt_PT.dic ${DATADIR}/
	${LN} -s hyph_pt_PT.dic ${DATADIR}/hyph_pt_BR.dic

.include <bsd.port.mk>
