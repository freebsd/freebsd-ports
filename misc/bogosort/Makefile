# New ports collection makefile for:	bogosort
# Date created:		15 September 2000
# Whom:			roam@orbitel.bg
#
# $FreeBSD$
#

PORTNAME=	bogosort
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.lysator.liu.se/~qha/bogosort/ \
		ftp://l82.ryd.student.liu.se/pub/unix/bogosort/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	"Sort (or not) stdin using the bogo-sort algorithm"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes

MAN1=		bogosort.1
INFO=		bogosort
PLIST_FILES=	bin/bogosort

test:		all
		${PRINTF} "a\nb\nc\nd\n" > ${WRKDIR}/sorted
		${PRINTF} "c\na\n\d\nb\n" > ${WRKDIR}/unsorted
		@${ECHO_MSG} "Testing bogosort"
		@${WRKSRC}/bogosort ${WRKDIR}/unsorted | diff - ${WRKDIR}/sorted && ${ECHO_MSG} "ok"
		@${ECHO_MSG} "Testing zbogotest"
		@${ECHO_MSG} "  ${WRKSRC}/bogosort.c"
		@${WRKSRC}/zbogotest ${WRKSRC}/bogosort.c || ${ECHO_MSG} "ok"
		@${ECHO_MSG} "  /dev/null"
		@${WRKSRC}/zbogotest /dev/null && ${ECHO_MSG} "ok"
		@${ECHO_MSG} "  ${WRKDIR}/unsorted"
		@${WRKSRC}/zbogotest ${WRKDIR}/unsorted || ${ECHO_MSG} "ok"
		@${ECHO_MSG} "  ${WRKDIR}/sorted"
		@${WRKSRC}/zbogotest ${WRKDIR}/sorted && ${ECHO_MSG} "ok"

.include <bsd.port.mk>
