# ex:ts=8
# New ports collection makefile for:	ttf2pt1
# Date created:			Aug 11, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ttf2pt1
PORTVERSION=	3.3.4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2

FREETYPE_CONFIG?=	${LOCALBASE}/bin/freetype-config
MAKE_ENV=	FREETYPE_CONFIG="${FREETYPE_CONFIG}"

MAN1=	ttf2pt1.1 ttf2pt1_convert.1 ttf2pt1_x2gs.1

.include <bsd.port.mk>
