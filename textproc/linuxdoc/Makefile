# New ports collection makefile for:	linuxdoc
# Version required:	1.1
# Date created:		July 8, 1997
# Whom:			jfieber
#
# $Id: Makefile,v 1.3 1997/07/10 02:34:31 jfieber Exp $
#

DISTNAME=	linuxdoc-1.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://fallout.campusview.indiana.edu/pub/sgml/

MAINTAINER=	jfieber@FreeBSD.ORG

RUN_DEPENDS=    ${ISOCAT}:${PORTSDIR}/textproc/iso8879

NO_MTREE=       yes
EXTRACT_ONLY=	# empty
NO_BUILD=       yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_WRKSUBDIR=	yes

INSTDIR=	${PREFIX}/share/sgml/linuxdoc
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}

do-install:
	@zcat ${DISTDIR}/${DISTFILES} |(cd ${INSTDIR}; pax -r)
	@chmod ${SHAREMODE} ${INSTDIR}/*
	@chown -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

.include <bsd.port.mk>
