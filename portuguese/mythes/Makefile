# New ports collection makefile for:	mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mythes
PORTVERSION=	2006.08.17
CATEGORIES=	portuguese textproc
MASTER_SITES=	http://openthesaurus.caixamagica.pt/download/
DISTNAME=	thes_pt_PT_v2

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Portuguese thesaurus

LICENSE=	GPLv2

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/mythes/th_pt_PT_v2.dat \
		share/mythes/th_pt_PT_v2.idx \
		share/mythes/th_pt_BR_v2.dat \
		share/mythes/th_pt_BR_v2.idx
PLIST_DIRS=	share/mythes

do-install:
	@${MKDIR} ${PREFIX}/share/mythes
	@${INSTALL_DATA} ${WRKDIR}/th_pt_PT_v2.* ${PREFIX}/share/mythes
	@cd ${PREFIX}/share/mythes; \
	${LN} -s th_pt_PT_v2.dat th_pt_BR_v2.dat ; \
	${LN} -s th_pt_PT_v2.idx th_pt_BR_v2.idx

.include <bsd.port.mk>
