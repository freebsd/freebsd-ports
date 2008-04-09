# New ports collection makefile for:	tkdiff
# Date created:		4 Oct. 1999
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkdiff
PORTVERSION=	4.1.4
CATEGORIES=	textproc tk
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-unix

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A Tk frontend for diff(1)

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

NO_BUILD=	yes

PLIST_FILES=	bin/tkdiff

post-patch:
	@${REINPLACE_CMD} -e 's|wish|wish8.4|' ${WRKSRC}/tkdiff

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/tkdiff ${PREFIX}/bin

.include <bsd.port.mk>
