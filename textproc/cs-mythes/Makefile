# New ports collection makefile for:	cs-mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cs-mythes
PORTVERSION=	2007.09.26
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
DISTNAME=	thes_cs_CZ_v2

MAINTAINER=	office@FreeBSD.org
COMMENT=	Czech thesaurus

LICENSE=	BSD

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/mythes/th_cs_CZ_v2.dat \
		share/mythes/th_cs_CZ_v2.idx
PLIST_DIRS=	share/mythes

do-install:
	@${MKDIR} ${PREFIX}/share/mythes
	@${INSTALL_DATA} ${WRKDIR}/th_cs_CZ_v2.* ${PREFIX}/share/mythes

.include <bsd.port.mk>
