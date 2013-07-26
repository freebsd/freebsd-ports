# New ports collection makefile for:	KDE iconset Noia Warm
# Date created:		Fri Feb 13 11:24:29 UTC 2004
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	noia-warm
PORTVERSION=	0.95
MASTER_SITES=	http://fc05.deviantart.com/files/icon/nixicons/
DISTNAME=	${PORTNAME:S/-//}kde${PORTVERSION:S/.//g}

COMMENT=	KDE iconset variation of the 'Noia' icons using warm colors

WRKSRC=		"${WRKDIR}/Noia Warm KDE ${PORTVERSION}"
PORT_SHAREDIR=	"${PORTNAME}-${PORTVERSION}"

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-08-27
BROKEN=		does not fetch

.include "${.CURDIR}/../kde-icons-noia/Makefile.icons"
