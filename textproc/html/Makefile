# New ports collection makefile for:	html
# Date created:		Sept 19, 1997
# Whom:			jfieber
#
# $FreeBSD$
#

PORTNAME=	html
PORTVERSION= 	4.0b
CATEGORIES=	textproc
MASTER_SITES=	http://fallout.campusview.indiana.edu/ports/distfiles/

MAINTAINER=	jfieber@FreeBSD.org

NO_MTREE=       yes
EXTRACT_ONLY=	# empty
NO_BUILD=       yes
NO_WRKSUBDIR=	yes

INSTDIR=	${PREFIX}/share/sgml/html

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}

do-install:
	@zcat ${DISTDIR}/${DISTFILES} |(cd ${INSTDIR}; pax -r)
	@${CHMOD} ${SHAREMODE} `find ${INSTDIR} -type f`
	@${CHOWN} -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

.include <bsd.port.mk>
