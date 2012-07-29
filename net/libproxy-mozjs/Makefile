# New ports collection makefile for:	libproxy-mozjs
# Date created:		26 February 2009
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net/libproxy-mozjs/Makefile,v 1.5 2011/01/12 13:10:53 kwm Exp $

PORTREVISION=	1
CATEGORIES=	net www
PKGNAMESUFFIX=	-mozjs

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mozilla JavaScript plug-in for libproxy

LIB_DEPENDS=	proxy.1:${PORTSDIR}/net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
USE_GECKO=	libxul

LIBPROXY_SLAVE=	mozjs

do-install:
	${INSTALL_LIB} ${WRKSRC}/libproxy/pacrunner_mozjs.so \
		${PREFIX}/lib/libproxy/${PORTVERSION}/modules/

.include "${MASTERDIR}/Makefile"
