# New ports collection makefile for:	html
# Date created:		Sept 19, 1997
# Whom:			jfieber
#
# $FreeBSD$
#

PORTNAME=	html
PORTVERSION= 	4.01
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
EXTRACT_ONLY=	# empty

MAINTAINER=	kuriyama@FreeBSD.org

NO_MTREE=       yes
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
