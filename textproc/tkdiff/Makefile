# New ports collection makefile for:	tkdiff
# Date created:		4 Oct. 1999
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkdiff
PORTVERSION=	4.0
CATEGORIES=	textproc tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_4_0

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A Tk frontend for diff(1)

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

WRKSRC=		${WRKDIR}/${PORTNAME}-unix

NO_BUILD=	yes

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/tkdiff

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkdiff ${PREFIX}/bin

.include <bsd.port.mk>
