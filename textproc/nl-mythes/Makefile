# New ports collection makefile for:	nl-mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nl-mythes
PORTVERSION=	2011.07.26
CATEGORIES=	textproc
MASTER_SITES=	http://data.opentaal.org/opentaalbank/thesaurus/download/
DISTNAME=	thes_nl
EXTRACT_SUFX=	.oxt

MAINTAINER=	office@FreeBSD.org
COMMENT=	Dutch thesaurus

LICENSE=	BSD

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/mythes/th_nl_NL_v2.dat \
		share/mythes/th_nl_NL_v2.idx
PLIST_DIRSTRY=	share/mythes

NLALIASES=	nl_AW nl_BE
.for ALIAS in ${NLALIASES}
PLIST_FILES+=	share/mythes/th_${ALIAS}_v2.dat \
		share/mythes/th_${ALIAS}_v2.idx
.endfor

do-install:
	${MKDIR} ${PREFIX}/share/mythes/
	${INSTALL_DATA} ${WRKDIR}/th_nl_v2.dat ${PREFIX}/share/mythes/th_nl_NL_v2.dat
	${INSTALL_DATA} ${WRKDIR}/th_nl_v2.dat ${PREFIX}/share/mythes/th_nl_NL_v2.idx
.for ALIAS in ${NLALIASES}
	${LN} -s th_nl_NL_v2.dat ${PREFIX}/share/mythes/th_${ALIAS}_v2.dat
	${LN} -s th_nl_NL_v2.idx ${PREFIX}/share/mythes/th_${ALIAS}_v2.idx
.endfor

.include <bsd.port.mk>
