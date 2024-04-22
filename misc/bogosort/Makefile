PORTNAME=	bogosort
PORTVERSION=	0.4.2
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://www.lysator.liu.se/~qha/bogosort/ \
		ftp://l82.ryd.student.liu.se/pub/unix/bogosort/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sort (or not) stdin using the bogo-sort algorithm
WWW=		https://www.lysator.liu.se/~qha/bogosort/

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INFO=		bogosort
PLIST_FILES=	bin/bogosort share/man/man1/bogosort.1.gz

.include <bsd.port.mk>
