# New ports collection makefile for:	misc/kde4-l10n-ro
# Date created:		2009-01-25
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde-l10n
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Romanian messages and documentation for KDE4

KDE4_L10N=	ro

post-extract:
	${MKDIR} ${WRKSRC}/build

.include "${.CURDIR}/../../misc/kde4-l10n/files/bsd.l10n.mk"
.include <bsd.port.mk>
