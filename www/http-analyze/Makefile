# New ports collection makefile for: http-analyze
# Date created:		Fri Jul 11 06:11:41 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$

PORTNAME=	http-analyze
PORTVERSION=	2.01
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.rent-a-guru.de/pub/http-analyze2.01/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	todd@thisisa.com
COMMENT=	A fast Log-Analyzer for web servers

BROKEN=		Broken gd dependency

BUILD_DEPENDS=	gif2png:${PORTSDIR}/graphics/gif2png
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd2

MAN1=		http-analyze.1

.include <bsd.port.mk>
