# New ports collection makefile for:	iso12083
# Date created:		July 9, 1997
# Whom:			jfieber
#
# $FreeBSD$
#

PORTNAME=	iso12083
PORTVERSION=	1993
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama/iso12083
DISTFILES=	article.dtd book.dtd maths.dtd serial.dtd
EXTRACT_ONLY=	# empty

MAINTAINER=	kuriyama@FreeBSD.org

RUN_DEPENDS=	${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

DIST_SUBDIR=	iso12083

NO_MTREE=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	DTD_NAME=${PORTNAME} MKCATALOG=${MKCATALOG}

INSTDIR=	${PREFIX}/share/sgml/iso12083
MKCATALOG=	${PREFIX}/sbin/mkcatalog

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}

do-install:
	@for i in ${DISTFILES}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$i ${INSTDIR}/$$i; \
	done
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/catalog

post-install:
	@${MKCATALOG} -q install ${PORTNAME}

.include <bsd.port.mk>
