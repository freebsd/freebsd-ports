# ex:ts=8
# New ports collection makefile for:	libxml++
# Date created:			Feb 26, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxml++
PORTVERSION=	0.14.p2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/+/plus/g}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
