# New ports collection makefile for:	linuxdoc
# Version required:	1.0
# Date created:		July 8, 1997
# Whom:			jfieber
#
# $Id$
#

DISTNAME=	linuxdoc-1.0
CATEGORIES=	textproc
MASTER_SITES=	ftp://fallout.campusview.indiana.edu/pub/sgml/

MAINTAINER=	jfieber@FreeBSD.ORG

NO_MTREE=       yes
NO_EXTRACT=     yes
NO_BUILD=       yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_WRKDIR=      yes

INSTDIR=	${PREFIX}/share/sgml/linuxdoc

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}

do-install:
	@zcat ${DISTDIR}/${DISTFILES} |(cd ${INSTDIR}; pax -r)
	@chmod ${SHAREMODE} ${INSTDIR}/*
	@chown -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

.include <bsd.port.mk>
