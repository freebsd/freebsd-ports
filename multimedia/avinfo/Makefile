# ex:ts=8
# Ports collection Makefile for:	avinfo
# Date created:			Feb 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	avinfo
PORTVERSION=	1.0.a15
CATEGORIES=	multimedia
MASTER_SITES=	http://shounen.ru/soft/avinfo/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}unix

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A utility for displaying AVI header information

USE_GMAKE=	yes
USE_BISON=	build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/avinfo

PORTDOCS=	*

MAN1=		avinfo.1

post-patch:
	@${REINPLACE_CMD} -e '/^CC=/ d; /^CFLAGS=/ d; /^PREFIX=/ d' \
		${WRKSRC}/config.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/avinfo ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/src/avinfo.1 ${MANPREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/README \
		${WRKSRC}/copying ${WRKSRC}/doc/* ${DOCSDIR}/
.endif

.include <bsd.port.mk>
