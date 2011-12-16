# New ports collection makefile for:	iogen
# Date created:		2011-12-14
# Whom:			Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iogen
PORTVERSION=	3.1p0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.peereboom.us/iogen/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Lightweight tool to generate heavily fragmented I/O

MAN8=		iogen.8
PLIST_FILES=	bin/iogen

WRKSRC=		${WRKDIR}/${DISTNAME}/src

do-build:
	cd ${WRKSRC}; \
	${CC} ${CFLAGS} -DVERSION=\"${PORTVERSION}\" iogen.c -o iogen

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iogen ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/iogen.8 ${MANPREFIX}/man/man8

.include <bsd.port.mk>
