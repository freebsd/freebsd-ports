# ex:ts=8
# Ports collection makefile for:	csv2latex
# Date created:			May 19, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	csv2latex
PORTVERSION=	20040213
CATEGORIES=	textproc
MASTER_SITES=	http://brouits.free.fr/share/utils/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts a well formed csv file to a LaTeX document

USE_GETOPT_LONG=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/csv2latex
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	.

do-build:
	@cd ${WRKSRC} && \
		${CC} ${CPPFLAGS} -o ${PORTNAME} ${PORTNAME}.c ${LDFLAGS}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
