# New ports collection makefile for:	KDE iconset Gartoon Blue
# Date created:		Mon Nov 15 20:30:10 UTC 2004
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gartoon
PORTVERSION=	1.3
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://ns.ael.ru/ports/distfiles/KDE/
MASTER_SITE_SUBDIR=	fluffy
PKGNAMESUFFIX=	-blue-svg
DISTNAME=	ICONS-Gartoon.Blue-SVG-v${PORTVERSION}

COMMENT=	KDE Gartoon Blue SVG iconset

USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/Gartoon.Blue
PORT_SHAREDIR?=	"${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}"

.include "${.CURDIR}/../kde-icons-noia/Makefile.icons"
