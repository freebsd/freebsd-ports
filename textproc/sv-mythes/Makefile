# New ports collection makefile for:	sv-mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sv-mythes
PORTVERSION=	2008.06.10
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
DISTNAME=	thes_sv_SE_v2

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Swedish thesaurus

LICENSE=	MIT

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/mythes/th_sv_SE.dat \
		share/mythes/th_sv_SE.idx \
		share/mythes/th_sv_FI.dat \
		share/mythes/th_sv_FI.idx
PLIST_DIRS=	share/mythes

do-install:
	@${MKDIR} ${PREFIX}/share/mythes
	@${INSTALL_DATA} ${WRKDIR}/th_sv_SE.* ${PREFIX}/share/mythes
	@cd ${PREFIX}/share/mythes; \
	${LN} -s th_sv_SE.dat th_sv_FI.dat; \
	${LN} -s th_sv_SE.idx th_sv_FI.idx

.include <bsd.port.mk>
