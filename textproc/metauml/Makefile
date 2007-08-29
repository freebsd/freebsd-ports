# New ports collection makefile for:	metauml
# Date created:		2007-08-29
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	metauml
PORTVERSION=	0.2.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_lib_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tota@rtfm.jp
COMMENT=	A MetaPost library for typesetting UML diagrams

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

WRKSRC=	${WRKDIR}/${PORTNAME}_lib

PLIST_SUB=	TEXMFDIR=${TEXMFDIR} MKTEXLSR=${MKTEXLSR} MPDIR=${MPDIR}

TEXMFDIR=	share/texmf
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
MPDIR=		${TEXMFDIR}/metapost/${PORTNAME}

NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/${MPDIR}
	${INSTALL_DATA} ${WRKSRC}/thrunk/*.mp ${PREFIX}/${MPDIR}

post-install:
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}

.include <bsd.port.mk>
