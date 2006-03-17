# ex:ts=8
# Ports collection makefile for:	csv2latex
# Date created:			May 19, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	csv2latex
PORTVERSION=	0.9.1
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	http://brouits.free.fr/csv2latex/
DISTNAME=	${PORTNAME}_${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts a well formed csv file to a LaTeX document

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_GETOPT_LONG=	yes

PLIST_FILES=	bin/csv2latex

do-build:
	cd ${WRKSRC} && \
		${CC} ${CPPFLAGS} -o ${PORTNAME} ${PORTNAME}.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
