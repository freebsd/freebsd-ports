# New ports collection makefile for:	tcping
# Date created:		2003-12-16
# Whom:			Dryice Liu
#
# $FreeBSD$
#

PORTNAME=	tcping
PORTVERSION=	1.3.3
CATEGORIES=	net
MASTER_SITES=	http://stud.fh-heilbronn.de/~kirchner/tcping/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dryice@liu.com.cn
COMMENT=	Do a TCP connect to the given IP/port combination

USE_GPG?=	yes
SIG_FILES=	${DISTNAME}${EXTRACT_SUFX}.asc
DOCS=		README

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -DHAVE_HSTRERROR -o tcping tcping.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcping ${PREFIX}/bin/tcping
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
