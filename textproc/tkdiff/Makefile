# New ports collection makefile for:	tkdiff
# Date created:		4 Oct. 1999
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkdiff
PORTVERSION=	4.1.4
PORTREVISION=	1
CATEGORIES=	textproc tk
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-unix

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A Tk frontend for diff(1)

USE_TK=		yes
NO_BUILD=	yes

PLIST_FILES=	bin/tkdiff

post-patch:
	@${REINPLACE_CMD} -e 's|wish|${WISH}|' ${WRKSRC}/tkdiff

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/tkdiff ${PREFIX}/bin

.include <bsd.port.mk>
