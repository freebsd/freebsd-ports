# New ports collection makefile for:    popup
# Date created:         18 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	popup
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://popup.sourceforge.net/files/cstack/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-stacks${PKGNAMESUFFIX2}
DISTFILES=	English-German.cstack.gz German-French.cstack.gz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Stacks for use with Popup

LICENSE=	GPLv2

NO_BUILD=	yes

WRKSRC=		${WRKDIR}
STACKS=		English-German.cstack German-French.cstack
PLIST_DIRS=	share/examples/popup
.for i in ${STACKS}
PLIST_FILES+=	share/examples/popup/${i}
.endfor

do-extract:
	${MKDIR} ${WRKDIR}
.for i in ${DISTFILES}
	${CP} ${DISTDIR}/${i} ${WRKDIR}/
	${GZIP_CMD} -d ${WRKDIR}/${i}
.endfor

do-install:
	${MKDIR} ${EXAMPLESDIR}
	(cd  ${WRKDIR} && ${INSTALL_DATA} ${STACKS} ${EXAMPLESDIR}/)

.include <bsd.port.mk>
