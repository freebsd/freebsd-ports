# ex:ts=8
# Ports collection makefile for:	palm-db-tools
# Date created:			Dec 25, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	palm-db-tools
PORTVERSION=	0.3.6
CATEGORIES=	palm
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Utilities for the PalmOS flat-file database programs

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libpdbtools.so \
		bin/csv2pdb \
		bin/pdb2csv

.include <bsd.port.mk>
