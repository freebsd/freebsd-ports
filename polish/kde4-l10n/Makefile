# New ports collection makefile for:    kde4-l10n-pl
# Date created:                         29 July 2008
# Whom:                                 Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde-l10n
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	polish kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Polish messages and documentation for KDE4

KDE4_L10N=	pl

post-extract:
	${MKDIR} ${WRKSRC}/build

.include "${.CURDIR}/../../misc/kde4-l10n/files/bsd.l10n.mk"
.include <bsd.port.mk>
