# New ports collection makefile for:	html
# Version required:	4.0
# Date created:		Sept 19, 1997
# Whom:			jfieber
#
# $Id: Makefile,v 1.2 1998/06/05 16:33:06 jfieber Exp $
#

DISTNAME=	html-4.0b
CATEGORIES=	textproc
MASTER_SITES=	ftp://fallout.campusview.indiana.edu/pub/sgml/

MAINTAINER=	jfieber@FreeBSD.ORG

NO_MTREE=       yes
EXTRACT_ONLY=	# empty
NO_BUILD=       yes
NO_WRKSUBDIR=	yes

INSTDIR=	${PREFIX}/share/sgml/html

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}

do-install:
	@zcat ${DISTDIR}/${DISTFILES} |(cd ${INSTDIR}; pax -r)
	@chmod ${SHAREMODE} `find ${INSTDIR} -type f`
	@chown -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

.include <bsd.port.mk>
