# ex:ts=8
# Ports collection Makefile for:	avinfo
# Date created:			Feb 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	avinfo
PORTVERSION=	0.6
CATEGORIES=	graphics
MASTER_SITES=	http://anime.org.ru/soft/avinfo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility for displaying AVI header information

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/src

post-patch:
	@(cd ${WRKSRC} && ${CP} messages.c temp ; \
		${CAT} temp | col -b > messages.c)

do-build:
	@(cd ${WRKSRC} && ${CC} ${CFLAGS} -o avinfo avinfo.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/avinfo ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../DOC/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
