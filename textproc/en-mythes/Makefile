# New ports collection makefile for:	en-mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	en-mythes
PORTVERSION=	2006.12.08
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
DISTNAME=	thes_en_US_v2

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	English thesaurus

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes

USALIASES=	en_AG en_AU en_BS en_BW en_BZ en_CA en_DK en_GB en_GH en_IE \
		en_IN en_JM en_NA en_NG en_NZ en_PH en_SG en_TT en_ZA en_ZW

PLIST_FILES=	share/mythes/th_en_US_v2.dat \
		share/mythes/th_en_US_v2.idx

.for ALIAS in ${USALIASES}
PLIST_FILES+=	share/mythes/th_${ALIAS}_v2.dat \
		share/mythes/th_${ALIAS}_v2.idx
.endfor

PLIST_DIRS=	share/mythes

do-install:
	@${MKDIR} ${PREFIX}/share/mythes
	@${INSTALL_DATA} ${WRKDIR}/th_en_US_v2.* ${PREFIX}/share/mythes
	@cd ${PREFIX}/share/mythes; \
	for alias in ${USALIASES}; do \
	  ${LN} -s th_en_US_v2.idx th_$${alias}_v2.idx ; \
	  ${LN} -s th_en_US_v2.dat th_$${alias}_v2.dat ; \
	done

.include <bsd.port.mk>
