# New ports collection makefile for:   oneko
# Date created:        5 December 1994
# Whom:                asami
#
# $FreeBSD$
#

PORTNAME=	am-utils
PORTVERSION=	6.1.b4
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://ftp.am-utils.org/pub/am-utils/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/b/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Berkeley Automounter Suite of Utilities

INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15

.if defined(WITH_OPENLDAP) || defined(PACKAGE_BUILDING)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldap=yes --enable-ldflags=-L${LOCALBASE}/lib --enable-cppflags=-I${LOCALBASE}/include
.endif

INFO=		am-utils
MAN1=		expn.1 pawd.1
MAN5=		amd.conf.5
MAN8=		amd.8 amq.8 automount2amd.8 fixmount.8 fsinfo.8 hlfsd.8 mk-amd-map.8 wire-test.8

.include <bsd.port.mk>
