# New ports collection makefile for:	KDE iconset CrystalOSX
# Date created:		Sat Feb 21 08:36:31 UTC 2004
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	crystalosx
PORTVERSION=	0.1.1
MASTER_SITES=	http://mywebpages.comcast.net/c0d3monkey/
DISTNAME=	${PORTNAME}

COMMENT=	KDE iconset

USE_ZIP=	yes

NO_WRKSUBDIR=	yes

.include "${.CURDIR}/../kde-icons-noia/Makefile.icons"

PLIST_SUB+=	BUILD_COOKIE=${BUILD_COOKIE:S|^${WRKDIR}||:S|^/||} \
		CONFIGURE_COOKIE=${CONFIGURE_COOKIE:S|^${WRKDIR}||:S|^/||} \
		EXTRACT_COOKIE=${EXTRACT_COOKIE:S|^${WRKDIR}||:S|^/||} \
		PATCH_COOKIE=${PATCH_COOKIE:S|^${WRKDIR}||:S|^/||}
