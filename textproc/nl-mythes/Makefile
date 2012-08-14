# New ports collection makefile for:	nl-mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mythes
PORTVERSION=	2012.08.12
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
PKGNAMEPREFIX=	nl-
DISTNAME=	thes_nl-${PORTVERSION:C/\.//g}
EXTRACT_SUFX=	.oxt
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Dutch thesaurus

LICENSE=	BSD

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/th_nl_NL_v2.dat \
		%%DATADIR%%/th_nl_NL_v2.idx
PLIST_DIRSTRY=	%%DATADIR%%

NLALIASES=	nl_AW nl_BE
.for ALIAS in ${NLALIASES}
PLIST_FILES+=	%%DATADIR%%/th_${ALIAS}_v2.dat \
		%%DATADIR%%/th_${ALIAS}_v2.idx
.endfor

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/th_nl_v2.dat ${DATADIR}/th_nl_NL_v2.dat
	${INSTALL_DATA} ${WRKSRC}/th_nl_v2.dat ${DATADIR}/th_nl_NL_v2.idx
.for ALIAS in ${NLALIASES}
	${LN} -s th_nl_NL_v2.dat ${DATADIR}/th_${ALIAS}_v2.dat
	${LN} -s th_nl_NL_v2.idx ${DATADIR}/th_${ALIAS}_v2.idx
.endfor

.include <bsd.port.mk>
