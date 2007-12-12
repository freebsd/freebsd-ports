# New ports collection makefile for:	KDE iconset OS-K
# Date created:		Qua 12 Dez 2007 00:07:35 UTC
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	os-k
PORTVERSION=	1.15
MASTER_SITES=	http://nordbryggan.se/pub/
DISTNAME=	OS-K_v115

COMMENT=	KDE OS-K iconset

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/OS-K
PLIST_FILE_PATTERN_EXTRA=	-v "^\./(buildset|README)"

.include "${.CURDIR}/../kde-icons-noia/Makefile.icons"
