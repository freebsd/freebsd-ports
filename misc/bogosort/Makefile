# Created by: roam@orbitel.bg
# $FreeBSD$

PORTNAME=	bogosort
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.lysator.liu.se/~qha/bogosort/ \
		ftp://l82.ryd.student.liu.se/pub/unix/bogosort/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Sort (or not) stdin using the bogo-sort algorithm

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes

MAN1=		bogosort.1
INFO=		bogosort
PLIST_FILES=	bin/bogosort

.include <bsd.port.mk>
