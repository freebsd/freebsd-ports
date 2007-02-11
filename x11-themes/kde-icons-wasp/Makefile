# New ports collection makefile for:	KDE iconset Wasp
# Date created:		Fri Feb 13 11:24:29 UTC 2004
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wasp
PORTVERSION=	2.6.1
MASTER_SITES=	http://steflo.dk/kde-look/
DISTNAME=	Wasp.SVG.Icons-v${PORTVERSION}

COMMENT=	KDE Wasp SVG iconset

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/Wasp
PORT_SHAREDIR?=	"${PORTNAME}-${PORTVERSION}"

BROKEN=		Unfetchable
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2007-04-10

.include "${.CURDIR}/../kde-icons-noia/Makefile.icons"
