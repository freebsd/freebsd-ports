# New ports collection makefile for:	KDE iconset Gartoon
# Date created:		Mon Nov 15 20:30:10 UTC 2004
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gartoon
PORTVERSION=	1.3
MASTER_SITES=	http://www.nasland.nu/gartoon/
PKGNAMESUFFIX=	-svg
DISTNAME=	ICONS-Gartoon-SVG-v${PORTVERSION}

COMMENT=	KDE Gartoon SVG iconset

USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/Gartoon
PORT_SHAREDIR?=	"${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}"

PLIST_DIR_PATTERN_EXTRA=	-v "extra/work"
PLIST_FILE_PATTERN_EXTRA=	-v "extra/work"

.include "${.CURDIR}/../kde-icons-noia/Makefile.icons"
