# New ports collection makefile for:	ezxml
# Date created:				27th July 2005
# Whom:					Marcin Jessa <yazzy@yazzy.org>
#
# $FreeBSD$
#

PORTNAME=	ezxml
PORTVERSION=	0.8.6
CATEGORIES=	textproc devel
MASTER_SITES=	SF/${PORTNAME}/ezXML/ezXML%20${PORTVERSION} \
		http://www.yazzy.org/ports/ezxml/


MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy to use C library for parsing XML documents

WRKSRC=		${WRKDIR}/${PORTNAME}

LIBFILES=	libezxml.a
HEADERFILES=	ezxml.h

PLIST_FILES=	include/${HEADERFILES} \
		lib/${LIBFILES}

.if !defined(NOPORTDOCS)
PLIST_FILES+=	%%EXAMPLESDIR%%/ezxml.txt
PLIST_DIRS=	%%EXAMPLESDIR%%
.endif

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_DATA} ${WRKSRC}/${LIBFILES} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/${HEADERFILES} ${PREFIX}/include

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ezxml.txt ${EXAMPLESDIR}
	@${ECHO} "An example of how to use the ezXML library can be found in"
	@${ECHO} "${EXAMPLESDIR}"
.endif

.include <bsd.port.post.mk>
