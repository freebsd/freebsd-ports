# New ports collection makefile for:	tkdiff
# Date created:		4 Oct. 1999
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkdiff
PORTVERSION=	3.05
CATEGORIES=	textproc tk83
MASTER_SITES=	http://people.freebsd.org/~kevlo/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A Tk frontend for diff(1)

RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83

NO_BUILD=	yes

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/tkdiff

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkdiff-3.05.tcl.txt ${PREFIX}/bin/tkdiff

.include <bsd.port.mk>
