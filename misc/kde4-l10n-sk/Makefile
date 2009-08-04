# New ports collection makefile for:	kde4-l10n-sk
# Date created:		2009-03-31
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde-l10n
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Slovak messages and documentation for KDE4

KDE4_L10N=	sk

MANLANG=	${KDE4_L10N}

post-extract:
	${MKDIR} ${WRKSRC}/build

.include "${.CURDIR}/../../misc/kde4-l10n/files/bsd.l10n.mk"
.include <bsd.port.mk>
